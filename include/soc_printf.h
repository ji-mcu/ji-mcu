#ifndef _SOC_PRINTF_
#define _SOC_PRINTF_

#ifdef __cplusplus
extern "C"
{
#endif



#define max(a, b) (((a) > (b)) ? (a) : (b))

#define soc_log_printf(fmt, args...) soc_myprintf(fmt, ##args)
#define soc_printf(fmt, args...) soc_log_printf(fmt, ##args)

    // extern int soc_myprintf(char *fmt, ...);

    void soc_myputchar(unsigned char chr);
    int soc_puts(char *s);
    int soc_printbase(long v, int w, int base, int sign);
    int soc_myprintf(char *fmt, ...);

#ifdef __cplusplus
}
#endif

#endif // _SOC_PRINTF_
