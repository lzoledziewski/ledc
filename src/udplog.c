#include "esp_log.h"
#include "lwip/sockets.h"
#include "credentials.h"

static int sock = -1;
static struct sockaddr_in dst;
vprintf_like_t default_logger;
int  udplog_printf(const char * str, va_list list)
{
    static char buffer[1024];
    int ret = vsnprintf(buffer, sizeof(buffer), str, list);
    sendto(sock, buffer,ret, 0, (struct sockaddr *)&dst, sizeof(dst));
    return default_logger(str, list);
}
void udplog_start(void)
{
    default_logger = esp_log_set_vprintf(udplog_printf);
    sock = socket(AF_INET, SOCK_DGRAM, 0);
    fcntl(sock, F_SETFL, O_NONBLOCK);
    dst.sin_addr.s_addr = inet_addr(LOG_IP_ADDR);
    dst.sin_family = AF_INET;
    dst.sin_port = htons(666);
    
}