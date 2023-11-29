#include <sys/time.h>
#include <sys/resource.h>
#include <unistd.h>
#include <time.h>

struct rusage r_usage;
struct timeval start, end;