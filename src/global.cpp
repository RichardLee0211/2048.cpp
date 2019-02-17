#include "global.hpp"
#include <sstream>

#ifdef _WIN32

void getInput(char &c) {
  std::cin >> c;
}

#else
#  include <termios.h>
#  include <unistd.h>

char getch() {
  char buf = 0;
  struct termios old = {0};
  if (tcgetattr(0, &old) < 0)
    perror("tcsetattr()");
  old.c_lflag &= ~ICANON;
  old.c_lflag &= ~ECHO;
  old.c_cc[VMIN] = 1;
  old.c_cc[VTIME] = 0;
  if (tcsetattr(0, TCSANOW, &old) < 0)
    perror("tcsetattr ICANON");
  if (read(0, &buf, 1) < 0)
    perror("read()");
  old.c_lflag |= ICANON;
  old.c_lflag |= ECHO;
  if (tcsetattr(0, TCSADRAIN, &old) < 0)
    perror("tcsetattr ~ICANON");
  return (buf);
}

void getInput(char &c) {
  c = getch();
}

#endif

void endl(int n) {

  for (int i = 0; i < n; i++) {
    std::cout << std::endl;
  }
};

void clearScreen() {
  system("clear");
};

std::string secondsFormat(double sec) {
  double s = sec;
  int m = s / 60;
  s -= m * 60;
  int h = m / 60;
  m %= 60;
  s = (int)s;
  std::ostringstream oss;
  if (h) {
    oss << h << "h ";
  }
  if (m) {
    oss << m << "m ";
  }
  oss << s << "s";
  return oss.str();
}

/* wenchen: could believe I would put client code here */
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define BUF_SIZE 500

#define IP "10.0.5.18"
#define PORT "8888"

int wenchen_upload(char* ptr, uint ptr_size){

    struct addrinfo hints;
    struct addrinfo *result, *rp;
    int sfd, s, j;
    long len;
    ssize_t nread;
    char buf[BUF_SIZE];

    char ip[] = IP;
    char port[] = PORT;

    /* Obtain address(es) matching host/port */

    memset(&hints, 0, sizeof(struct addrinfo));
    hints.ai_family = AF_UNSPEC;    /* Allow IPv4 or IPv6 */
    hints.ai_socktype = SOCK_DGRAM; /* Datagram socket */
    hints.ai_flags = 0;
    hints.ai_protocol = 0;          /* Any protocol */

    s = getaddrinfo(ip, port, &hints, &result);
    if (s != 0) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(s));
        exit(EXIT_FAILURE);
    }

    /* getaddrinfo() returns a list of address structures.
     * Try each address until we successfully connect(2).
     * If socket(2) (or connect(2)) fails, we (close the socket
     * and) try the next address. */

    for (rp = result; rp != NULL; rp = rp->ai_next) {
        sfd = socket(rp->ai_family, rp->ai_socktype,
                rp->ai_protocol);
        if (sfd == -1)
            continue;

        if (connect(sfd, rp->ai_addr, rp->ai_addrlen) != -1)
            break;                  /* Success */

        close(sfd);
    }

    if (rp == NULL) {               /* No address succeeded */
        fprintf(stderr, "Could not connect\n");
        exit(EXIT_FAILURE);
    }

    freeaddrinfo(result);           /* No longer needed */

    /* Send remaining command-line arguments as separate
     * datagrams, and read responses from server */

    len = ptr_size + 1;
    /* +1 for terminating null byte */


    if (write(sfd, ptr, len) != len) {
      fprintf(stderr, "partial/failed write\n");
      exit(EXIT_FAILURE);
    }

    nread = read(sfd, buf, BUF_SIZE);
    if (nread == -1) {
      perror("read");
      exit(EXIT_FAILURE);
    }

    printf("Received %zd bytes: %s\n", nread, buf);

    // exit(EXIT_SUCCESS);
    return 0;
}
