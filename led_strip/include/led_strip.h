/*
 * SPDX-FileCopyrightText: 2022 Espressif Systems (Shanghai) CO LTD
 *
 * SPDX-License-Identifier: Apache-2.0
 */
#pragma once

#include <stdint.h>
#include "esp_err.h"
#include "led_strip_rmt.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Set RGB for a specific pixel
 *
 * @param strip: LED strip
 * @param index: index of pixel to set
 * @param red: red part of color
 * @param green: green part of color
 * @param blue: blue part of color
 *
 * @return
 *      - ESP_OK: Set RGB for a specific pixel successfully
 *      - ESP_ERR_INVALID_ARG: Set RGB for a specific pixel failed because of invalid parameters
 *      - ESP_FAIL: Set RGB for a specific pixel failed because other error occurred
 */
esp_err_t led_strip_set_pixel(led_strip_handle_t strip, uint32_t index, uint32_t red, uint32_t green, uint32_t blue);

/**
 * @brief Set RGBW for a specific pixel
 *
 * @note Only call this function if your led strip does have the white component (e.g. SK6812-RGBW)
 * @note Also see `led_strip_set_pixel` if you only want to specify the RGB part of the color and bypass the white component
 *
 * @param strip: LED strip
 * @param index: index of pixel to set
 * @param red: red part of color
 * @param green: green part of color
 * @param blue: blue part of color
 * @param white: separate white component
 *
 * @return
 *      - ESP_OK: Set RGBW color for a specific pixel successfully
 *      - ESP_ERR_INVALID_ARG: Set RGBW color for a specific pixel failed because of an invalid argument
 *      - ESP_FAIL: Set RGBW color for a specific pixel failed because other error occurred
 */
esp_err_t led_strip_set_pixel_rgbw(led_strip_handle_t strip, uint32_t index, uint32_t red, uint32_t green, uint32_t blue, uint32_t white);

/**
 * @brief Inserts the given color at the back, shifting all pixel 1 down and dropping the pixel at index 0
 *
 * @param strip: LED strip
 * @param index: index of pixel to set
 * @param red: red part of color
 * @param green: green part of color
 * @param blue: blue part of color
 *
 * @return
 *      - ESP_OK: Push of RGB pixel successful
 *      - ESP_ERR_INVALID_ARG: Failed to push the pixel into the led strip because of an invalid argument
 *      - ESP_FAIL: Failed to push the pixel into the led strip because some other error occurred
 */
esp_err_t led_strip_reverse_pixel_insert(led_strip_handle_t strip, uint32_t index, uint32_t red, uint32_t green, uint32_t blue);

/**
 * @brief Inserts the given color at the back, shifting all pixel 1 down and dropping the pixel at index 0
 *
 * @param strip: LED strip
 * @param index: index of pixel to set
 * @param red: red part of color
 * @param green: green part of color
 * @param blue: blue part of color
 * @param white: separate white component
 *
 * @return
 *      - ESP_OK: Push of RGBW pixel successful
 *      - ESP_ERR_INVALID_ARG: Failed to push the pixel into the led strip because of an invalid argument
 *      - ESP_FAIL: Failed to push the pixel into the led strip because some other error occurred
 */
esp_err_t led_strip_reverse_insert_pixel_rgbw(led_strip_handle_t strip, uint32_t index, uint32_t red, uint32_t green, uint32_t blue, uint32_t white);

/**
 * @brief Inserts the given color at the given index, shifting the remaining pixels 1 up and dropping the last pixel
 *
 * @param strip: LED strip
 * @param index: index of pixel to set
 * @param red: red part of color
 * @param green: green part of color
 * @param blue: blue part of color
 *
 * @return
 *      - ESP_OK: Successfully addition of the RGB pixel
 *      - ESP_ERR_INVALID_ARG: Failed to insert the pixel in the led strip because of an invalid argument
 *      - ESP_FAIL: Failed to insert the pixel in the led strip because some other error occurred
 */
esp_err_t led_strip_insert_pixel(led_strip_handle_t strip, uint32_t index, uint32_t red, uint32_t green, uint32_t blue);

/**
 * @brief Inserts the given color at the given index, shifting the remaining pixels 1 up and dropping the last pixel
 *
 * @param strip: LED strip
 * @param index: index of pixel to set
 * @param red: red part of color
 * @param green: green part of color
 * @param blue: blue part of color
 * @param white: separate white component
 *
 * @return
 *      - ESP_OK: Successfully addition of the RGBW pixel
 *      - ESP_ERR_INVALID_ARG: Failed to push the pixel into the led strip because of an invalid argument
 *      - ESP_FAIL: Failed to push the pixel into the led strip because some other error occurred
 */
esp_err_t led_strip_insert_pixel_rgbw(led_strip_handle_t strip, uint32_t index, uint32_t red, uint32_t green, uint32_t blue, uint32_t white);

/**
 * @brief Refresh memory colors to LEDs
 *
 * @param strip: LED strip
 *
 * @return
 *      - ESP_OK: Refresh successfully
 *      - ESP_FAIL: Refresh failed because some other error occurred
 *
 * @note:
 *      After updating the LED colors in the memory, a following invocation of this API is needed to flush colors to strip.
 */
esp_err_t led_strip_refresh(led_strip_handle_t strip);

/**
 * @brief Clear LED strip (turn off all LEDs)
 *
 * @param strip: LED strip
 *
 * @return
 *      - ESP_OK: Clear LEDs successfully
 *      - ESP_FAIL: Clear LEDs failed because some other error occurred
 */
esp_err_t led_strip_clear(led_strip_handle_t strip);

/**
 * @brief Free LED strip resources
 *
 * @param strip: LED strip
 *
 * @return
 *      - ESP_OK: Free resources successfully
 *      - ESP_FAIL: Free resources failed because error occurred
 */
esp_err_t led_strip_del(led_strip_handle_t strip);

#ifdef __cplusplus
}
#endif
