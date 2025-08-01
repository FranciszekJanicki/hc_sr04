#ifndef HC_SR04_HC_SR04_CONFIG_H
#define HC_SR04_HC_SR04_CONFIG_H

#include <stdbool.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef enum {
    HC_SR04_ERR_OK = 0,
    HC_SR04_ERR_FAIL = 1 << 0,
    HC_SR04_ERR_NULL = 1 << 1,
} hc_sr04_err_t;

typedef struct {
    uint32_t pin_trig;
    uint32_t pin_echo;
} hc_sr04_config_t;

typedef struct {
    void* gpio_user;
    hc_sr04_err_t (*gpio_initialize)(void*);
    hc_sr04_err_t (*gpio_deinitialize)(void*);
    hc_sr04_err_t (*gpio_write)(void*, uint32_t, bool);
    hc_sr04_err_t (*gpio_read)(void*, uint32_t, bool*);

    void* timer_user;
    hc_sr04_err_t (*timer_initialize)(void*);
    hc_sr04_err_t (*timer_deinitialize)(void*);
    hc_sr04_err_t (*timer_start)(void*);
    hc_sr04_err_t (*timer_stop)(void*);
    hc_sr04_err_t (*timer_get_count)(void*, uint32_t*);
    hc_sr04_err_t (*timer_set_count)(void*, uint32_t);
    hc_sr04_err_t (*timer_delay_us)(void*, uint32_t);
} hc_sr04_interface_t;

#ifdef __cplusplus
}
#endif

#endif // HC_SR04_HC_SR04_CONFIG_H