SIMPLELINK_SDK_LVGL_PLUGIN_INSTALL_DIR ?= $(abspath ../../../../../../..)

include $(SIMPLELINK_SDK_LVGL_PLUGIN_INSTALL_DIR)/imports.mak

KERNEL_BUILD := $(SIMPLELINK_CC32XX_SDK_INSTALL_DIR)/kernel/freertos/builds/CC3220SF_LAUNCHXL/release

CC = "$(GCC_ARMCOMPILER)/bin/arm-none-eabi-gcc"
LNK = "$(GCC_ARMCOMPILER)/bin/arm-none-eabi-gcc"

OBJECTS = kentectouchwidgets.obj ti_lvgl_ssd2119_disp.obj lv_port_indev.obj ti_lvgl_disp_interface.obj freertos_main_freertos.obj CC3220SF_LAUNCHXL.obj lvgl_src_lv_core_lv_disp.obj lvgl_src_lv_core_lv_group.obj lvgl_src_lv_core_lv_indev.obj lvgl_src_lv_core_lv_obj.obj lvgl_src_lv_core_lv_refr.obj lvgl_src_lv_core_lv_style.obj lvgl_src_lv_draw_lv_draw.obj lvgl_src_lv_draw_lv_draw_arc.obj lvgl_src_lv_draw_lv_draw_basic.obj lvgl_src_lv_draw_lv_draw_img.obj lvgl_src_lv_draw_lv_draw_label.obj lvgl_src_lv_draw_lv_draw_line.obj lvgl_src_lv_draw_lv_draw_rect.obj lvgl_src_lv_draw_lv_draw_triangle.obj lvgl_src_lv_draw_lv_img_cache.obj lvgl_src_lv_draw_lv_img_decoder.obj lvgl_src_lv_font_lv_font.obj lvgl_src_lv_font_lv_font_fmt_txt.obj lvgl_src_lv_font_lv_font_roboto_12.obj lvgl_src_lv_font_lv_font_roboto_16.obj lvgl_src_lv_font_lv_font_roboto_22.obj lvgl_src_lv_font_lv_font_roboto_28.obj lvgl_src_lv_font_lv_font_unscii_8.obj lvgl_src_lv_hal_lv_hal_disp.obj lvgl_src_lv_hal_lv_hal_indev.obj lvgl_src_lv_hal_lv_hal_tick.obj lvgl_src_lv_misc_lv_anim.obj lvgl_src_lv_misc_lv_area.obj lvgl_src_lv_misc_lv_async.obj lvgl_src_lv_misc_lv_circ.obj lvgl_src_lv_misc_lv_color.obj lvgl_src_lv_misc_lv_fs.obj lvgl_src_lv_misc_lv_gc.obj lvgl_src_lv_misc_lv_ll.obj lvgl_src_lv_misc_lv_log.obj lvgl_src_lv_misc_lv_math.obj lvgl_src_lv_misc_lv_mem.obj lvgl_src_lv_misc_lv_task.obj lvgl_src_lv_misc_lv_templ.obj lvgl_src_lv_misc_lv_txt.obj lvgl_src_lv_misc_lv_utils.obj lvgl_src_lv_objx_lv_arc.obj lvgl_src_lv_objx_lv_bar.obj lvgl_src_lv_objx_lv_btn.obj lvgl_src_lv_objx_lv_btnm.obj lvgl_src_lv_objx_lv_calendar.obj lvgl_src_lv_objx_lv_canvas.obj lvgl_src_lv_objx_lv_cb.obj lvgl_src_lv_objx_lv_chart.obj lvgl_src_lv_objx_lv_cont.obj lvgl_src_lv_objx_lv_ddlist.obj lvgl_src_lv_objx_lv_gauge.obj lvgl_src_lv_objx_lv_img.obj lvgl_src_lv_objx_lv_imgbtn.obj lvgl_src_lv_objx_lv_kb.obj lvgl_src_lv_objx_lv_label.obj lvgl_src_lv_objx_lv_led.obj lvgl_src_lv_objx_lv_line.obj lvgl_src_lv_objx_lv_list.obj lvgl_src_lv_objx_lv_lmeter.obj lvgl_src_lv_objx_lv_mbox.obj lvgl_src_lv_objx_lv_objx_templ.obj lvgl_src_lv_objx_lv_page.obj lvgl_src_lv_objx_lv_preload.obj lvgl_src_lv_objx_lv_roller.obj lvgl_src_lv_objx_lv_slider.obj lvgl_src_lv_objx_lv_spinbox.obj lvgl_src_lv_objx_lv_sw.obj lvgl_src_lv_objx_lv_ta.obj lvgl_src_lv_objx_lv_table.obj lvgl_src_lv_objx_lv_tabview.obj lvgl_src_lv_objx_lv_tileview.obj lvgl_src_lv_objx_lv_win.obj lvgl_src_lv_themes_lv_theme.obj lvgl_src_lv_themes_lv_theme_alien.obj lvgl_src_lv_themes_lv_theme_default.obj lvgl_src_lv_themes_lv_theme_material.obj lvgl_src_lv_themes_lv_theme_mono.obj lvgl_src_lv_themes_lv_theme_nemo.obj lvgl_src_lv_themes_lv_theme_night.obj lvgl_src_lv_themes_lv_theme_templ.obj lvgl_src_lv_themes_lv_theme_zen.obj

NAME = kentectouchwidgets

CFLAGS = -I../.. \
    "-I$(SIMPLELINK_CC32XX_SDK_INSTALL_DIR)/source" \
    -DLV_CONF_INCLUDE_SIMPLE \
    "-I$(SIMPLELINK_SDK_LVGL_PLUGIN_INSTALL_DIR)/source" \
    "-I$(SIMPLELINK_SDK_LVGL_PLUGIN_INSTALL_DIR)/source/third_party" \
    "-I$(SIMPLELINK_SDK_LVGL_PLUGIN_INSTALL_DIR)/source/third_party/lvgl" \
    "-I$(SIMPLELINK_CC32XX_SDK_INSTALL_DIR)/source/ti/posix/gcc" \
    "-I$(FREERTOS_INSTALL_DIR)/FreeRTOS/Source/include" \
    "-I$(FREERTOS_INSTALL_DIR)/FreeRTOS/Source/portable/GCC/ARM_CM3" \
    "-I$(KERNEL_BUILD)" \
    -mcpu=cortex-m4 \
    -march=armv7e-m \
    -mthumb \
    -std=c99 \
    -mfloat-abi=soft \
    -ffunction-sections \
    -fdata-sections \
    -g \
    -gstrict-dwarf \
    -Wall \
    "-I$(GCC_ARMCOMPILER)/arm-none-eabi/include/newlib-nano" \
    "-I$(GCC_ARMCOMPILER)/arm-none-eabi/include"

LFLAGS = -Wl,-T,../../freertos/gcc/CC3220SF_LAUNCHXL_FREERTOS.lds \
    "-Wl,-Map,$(NAME).map" \
    "-L$(SIMPLELINK_CC32XX_SDK_INSTALL_DIR)/source" \
    -l:ti/display/lib/display.am4g \
    -l:ti/grlib/lib/gcc/m4/grlib.a \
    -l:third_party/spiffs/lib/gcc/m4/spiffs.a \
    -l:ti/drivers/lib/drivers_cc32xx.am4g \
    -l:third_party/fatfs/lib/gcc/m4/fatfs.a \
    "-L$(KERNEL_BUILD)/gcc" \
    -l:freertos.lib \
    -l:ti/devices/cc32xx/driverlib/gcc/Release/driverlib.a \
    -march=armv7e-m \
    -mthumb \
    -nostartfiles \
    -static \
    -Wl,--gc-sections \
    "-L$(GCC_ARMCOMPILER)/arm-none-eabi/lib/thumb/v7e-m" \
    "-L$(GCC_ARMCOMPILER)/arm-none-eabi/lib" \
    -lgcc \
    -lc \
    -lm \
    -lnosys \
    --specs=nano.specs

all: $(NAME).out

$(KERNEL_BUILD)/gcc/freertos.lib:
	@ $(ECHOBLANKLINE)
	@ echo $@ is not built.
	@ echo You can build it by issuing $(MAKE) in $(dir $@).
	@ $(ECHOBLANKLINE)

kentectouchwidgets.obj: ../../kentectouchwidgets.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< -c -o $@

ti_lvgl_ssd2119_disp.obj: ../../ti_lvgl_ssd2119_disp.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< -c -o $@

lv_port_indev.obj: ../../lv_port_indev.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< -c -o $@

ti_lvgl_disp_interface.obj: ../../ti_lvgl_disp_interface.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< -c -o $@

freertos_main_freertos.obj: ../../freertos/main_freertos.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< -c -o $@

CC3220SF_LAUNCHXL.obj: ../../CC3220SF_LAUNCHXL.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< -c -o $@

lvgl_src_lv_core_lv_disp.obj: $(SIMPLELINK_SDK_LVGL_PLUGIN_INSTALL_DIR)/source/third_party/lvgl/src/lv_core/lv_disp.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< -c -o $@

lvgl_src_lv_core_lv_group.obj: $(SIMPLELINK_SDK_LVGL_PLUGIN_INSTALL_DIR)/source/third_party/lvgl/src/lv_core/lv_group.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< -c -o $@

lvgl_src_lv_core_lv_indev.obj: $(SIMPLELINK_SDK_LVGL_PLUGIN_INSTALL_DIR)/source/third_party/lvgl/src/lv_core/lv_indev.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< -c -o $@

lvgl_src_lv_core_lv_obj.obj: $(SIMPLELINK_SDK_LVGL_PLUGIN_INSTALL_DIR)/source/third_party/lvgl/src/lv_core/lv_obj.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< -c -o $@

lvgl_src_lv_core_lv_refr.obj: $(SIMPLELINK_SDK_LVGL_PLUGIN_INSTALL_DIR)/source/third_party/lvgl/src/lv_core/lv_refr.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< -c -o $@

lvgl_src_lv_core_lv_style.obj: $(SIMPLELINK_SDK_LVGL_PLUGIN_INSTALL_DIR)/source/third_party/lvgl/src/lv_core/lv_style.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< -c -o $@

lvgl_src_lv_draw_lv_draw.obj: $(SIMPLELINK_SDK_LVGL_PLUGIN_INSTALL_DIR)/source/third_party/lvgl/src/lv_draw/lv_draw.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< -c -o $@

lvgl_src_lv_draw_lv_draw_arc.obj: $(SIMPLELINK_SDK_LVGL_PLUGIN_INSTALL_DIR)/source/third_party/lvgl/src/lv_draw/lv_draw_arc.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< -c -o $@

lvgl_src_lv_draw_lv_draw_basic.obj: $(SIMPLELINK_SDK_LVGL_PLUGIN_INSTALL_DIR)/source/third_party/lvgl/src/lv_draw/lv_draw_basic.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< -c -o $@

lvgl_src_lv_draw_lv_draw_img.obj: $(SIMPLELINK_SDK_LVGL_PLUGIN_INSTALL_DIR)/source/third_party/lvgl/src/lv_draw/lv_draw_img.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< -c -o $@

lvgl_src_lv_draw_lv_draw_label.obj: $(SIMPLELINK_SDK_LVGL_PLUGIN_INSTALL_DIR)/source/third_party/lvgl/src/lv_draw/lv_draw_label.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< -c -o $@

lvgl_src_lv_draw_lv_draw_line.obj: $(SIMPLELINK_SDK_LVGL_PLUGIN_INSTALL_DIR)/source/third_party/lvgl/src/lv_draw/lv_draw_line.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< -c -o $@

lvgl_src_lv_draw_lv_draw_rect.obj: $(SIMPLELINK_SDK_LVGL_PLUGIN_INSTALL_DIR)/source/third_party/lvgl/src/lv_draw/lv_draw_rect.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< -c -o $@

lvgl_src_lv_draw_lv_draw_triangle.obj: $(SIMPLELINK_SDK_LVGL_PLUGIN_INSTALL_DIR)/source/third_party/lvgl/src/lv_draw/lv_draw_triangle.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< -c -o $@

lvgl_src_lv_draw_lv_img_cache.obj: $(SIMPLELINK_SDK_LVGL_PLUGIN_INSTALL_DIR)/source/third_party/lvgl/src/lv_draw/lv_img_cache.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< -c -o $@

lvgl_src_lv_draw_lv_img_decoder.obj: $(SIMPLELINK_SDK_LVGL_PLUGIN_INSTALL_DIR)/source/third_party/lvgl/src/lv_draw/lv_img_decoder.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< -c -o $@

lvgl_src_lv_font_lv_font.obj: $(SIMPLELINK_SDK_LVGL_PLUGIN_INSTALL_DIR)/source/third_party/lvgl/src/lv_font/lv_font.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< -c -o $@

lvgl_src_lv_font_lv_font_fmt_txt.obj: $(SIMPLELINK_SDK_LVGL_PLUGIN_INSTALL_DIR)/source/third_party/lvgl/src/lv_font/lv_font_fmt_txt.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< -c -o $@

lvgl_src_lv_font_lv_font_roboto_12.obj: $(SIMPLELINK_SDK_LVGL_PLUGIN_INSTALL_DIR)/source/third_party/lvgl/src/lv_font/lv_font_roboto_12.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< -c -o $@

lvgl_src_lv_font_lv_font_roboto_16.obj: $(SIMPLELINK_SDK_LVGL_PLUGIN_INSTALL_DIR)/source/third_party/lvgl/src/lv_font/lv_font_roboto_16.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< -c -o $@

lvgl_src_lv_font_lv_font_roboto_22.obj: $(SIMPLELINK_SDK_LVGL_PLUGIN_INSTALL_DIR)/source/third_party/lvgl/src/lv_font/lv_font_roboto_22.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< -c -o $@

lvgl_src_lv_font_lv_font_roboto_28.obj: $(SIMPLELINK_SDK_LVGL_PLUGIN_INSTALL_DIR)/source/third_party/lvgl/src/lv_font/lv_font_roboto_28.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< -c -o $@

lvgl_src_lv_font_lv_font_unscii_8.obj: $(SIMPLELINK_SDK_LVGL_PLUGIN_INSTALL_DIR)/source/third_party/lvgl/src/lv_font/lv_font_unscii_8.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< -c -o $@

lvgl_src_lv_hal_lv_hal_disp.obj: $(SIMPLELINK_SDK_LVGL_PLUGIN_INSTALL_DIR)/source/third_party/lvgl/src/lv_hal/lv_hal_disp.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< -c -o $@

lvgl_src_lv_hal_lv_hal_indev.obj: $(SIMPLELINK_SDK_LVGL_PLUGIN_INSTALL_DIR)/source/third_party/lvgl/src/lv_hal/lv_hal_indev.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< -c -o $@

lvgl_src_lv_hal_lv_hal_tick.obj: $(SIMPLELINK_SDK_LVGL_PLUGIN_INSTALL_DIR)/source/third_party/lvgl/src/lv_hal/lv_hal_tick.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< -c -o $@

lvgl_src_lv_misc_lv_anim.obj: $(SIMPLELINK_SDK_LVGL_PLUGIN_INSTALL_DIR)/source/third_party/lvgl/src/lv_misc/lv_anim.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< -c -o $@

lvgl_src_lv_misc_lv_area.obj: $(SIMPLELINK_SDK_LVGL_PLUGIN_INSTALL_DIR)/source/third_party/lvgl/src/lv_misc/lv_area.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< -c -o $@

lvgl_src_lv_misc_lv_async.obj: $(SIMPLELINK_SDK_LVGL_PLUGIN_INSTALL_DIR)/source/third_party/lvgl/src/lv_misc/lv_async.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< -c -o $@

lvgl_src_lv_misc_lv_circ.obj: $(SIMPLELINK_SDK_LVGL_PLUGIN_INSTALL_DIR)/source/third_party/lvgl/src/lv_misc/lv_circ.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< -c -o $@

lvgl_src_lv_misc_lv_color.obj: $(SIMPLELINK_SDK_LVGL_PLUGIN_INSTALL_DIR)/source/third_party/lvgl/src/lv_misc/lv_color.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< -c -o $@

lvgl_src_lv_misc_lv_fs.obj: $(SIMPLELINK_SDK_LVGL_PLUGIN_INSTALL_DIR)/source/third_party/lvgl/src/lv_misc/lv_fs.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< -c -o $@

lvgl_src_lv_misc_lv_gc.obj: $(SIMPLELINK_SDK_LVGL_PLUGIN_INSTALL_DIR)/source/third_party/lvgl/src/lv_misc/lv_gc.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< -c -o $@

lvgl_src_lv_misc_lv_ll.obj: $(SIMPLELINK_SDK_LVGL_PLUGIN_INSTALL_DIR)/source/third_party/lvgl/src/lv_misc/lv_ll.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< -c -o $@

lvgl_src_lv_misc_lv_log.obj: $(SIMPLELINK_SDK_LVGL_PLUGIN_INSTALL_DIR)/source/third_party/lvgl/src/lv_misc/lv_log.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< -c -o $@

lvgl_src_lv_misc_lv_math.obj: $(SIMPLELINK_SDK_LVGL_PLUGIN_INSTALL_DIR)/source/third_party/lvgl/src/lv_misc/lv_math.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< -c -o $@

lvgl_src_lv_misc_lv_mem.obj: $(SIMPLELINK_SDK_LVGL_PLUGIN_INSTALL_DIR)/source/third_party/lvgl/src/lv_misc/lv_mem.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< -c -o $@

lvgl_src_lv_misc_lv_task.obj: $(SIMPLELINK_SDK_LVGL_PLUGIN_INSTALL_DIR)/source/third_party/lvgl/src/lv_misc/lv_task.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< -c -o $@

lvgl_src_lv_misc_lv_templ.obj: $(SIMPLELINK_SDK_LVGL_PLUGIN_INSTALL_DIR)/source/third_party/lvgl/src/lv_misc/lv_templ.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< -c -o $@

lvgl_src_lv_misc_lv_txt.obj: $(SIMPLELINK_SDK_LVGL_PLUGIN_INSTALL_DIR)/source/third_party/lvgl/src/lv_misc/lv_txt.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< -c -o $@

lvgl_src_lv_misc_lv_utils.obj: $(SIMPLELINK_SDK_LVGL_PLUGIN_INSTALL_DIR)/source/third_party/lvgl/src/lv_misc/lv_utils.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< -c -o $@

lvgl_src_lv_objx_lv_arc.obj: $(SIMPLELINK_SDK_LVGL_PLUGIN_INSTALL_DIR)/source/third_party/lvgl/src/lv_objx/lv_arc.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< -c -o $@

lvgl_src_lv_objx_lv_bar.obj: $(SIMPLELINK_SDK_LVGL_PLUGIN_INSTALL_DIR)/source/third_party/lvgl/src/lv_objx/lv_bar.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< -c -o $@

lvgl_src_lv_objx_lv_btn.obj: $(SIMPLELINK_SDK_LVGL_PLUGIN_INSTALL_DIR)/source/third_party/lvgl/src/lv_objx/lv_btn.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< -c -o $@

lvgl_src_lv_objx_lv_btnm.obj: $(SIMPLELINK_SDK_LVGL_PLUGIN_INSTALL_DIR)/source/third_party/lvgl/src/lv_objx/lv_btnm.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< -c -o $@

lvgl_src_lv_objx_lv_calendar.obj: $(SIMPLELINK_SDK_LVGL_PLUGIN_INSTALL_DIR)/source/third_party/lvgl/src/lv_objx/lv_calendar.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< -c -o $@

lvgl_src_lv_objx_lv_canvas.obj: $(SIMPLELINK_SDK_LVGL_PLUGIN_INSTALL_DIR)/source/third_party/lvgl/src/lv_objx/lv_canvas.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< -c -o $@

lvgl_src_lv_objx_lv_cb.obj: $(SIMPLELINK_SDK_LVGL_PLUGIN_INSTALL_DIR)/source/third_party/lvgl/src/lv_objx/lv_cb.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< -c -o $@

lvgl_src_lv_objx_lv_chart.obj: $(SIMPLELINK_SDK_LVGL_PLUGIN_INSTALL_DIR)/source/third_party/lvgl/src/lv_objx/lv_chart.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< -c -o $@

lvgl_src_lv_objx_lv_cont.obj: $(SIMPLELINK_SDK_LVGL_PLUGIN_INSTALL_DIR)/source/third_party/lvgl/src/lv_objx/lv_cont.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< -c -o $@

lvgl_src_lv_objx_lv_ddlist.obj: $(SIMPLELINK_SDK_LVGL_PLUGIN_INSTALL_DIR)/source/third_party/lvgl/src/lv_objx/lv_ddlist.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< -c -o $@

lvgl_src_lv_objx_lv_gauge.obj: $(SIMPLELINK_SDK_LVGL_PLUGIN_INSTALL_DIR)/source/third_party/lvgl/src/lv_objx/lv_gauge.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< -c -o $@

lvgl_src_lv_objx_lv_img.obj: $(SIMPLELINK_SDK_LVGL_PLUGIN_INSTALL_DIR)/source/third_party/lvgl/src/lv_objx/lv_img.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< -c -o $@

lvgl_src_lv_objx_lv_imgbtn.obj: $(SIMPLELINK_SDK_LVGL_PLUGIN_INSTALL_DIR)/source/third_party/lvgl/src/lv_objx/lv_imgbtn.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< -c -o $@

lvgl_src_lv_objx_lv_kb.obj: $(SIMPLELINK_SDK_LVGL_PLUGIN_INSTALL_DIR)/source/third_party/lvgl/src/lv_objx/lv_kb.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< -c -o $@

lvgl_src_lv_objx_lv_label.obj: $(SIMPLELINK_SDK_LVGL_PLUGIN_INSTALL_DIR)/source/third_party/lvgl/src/lv_objx/lv_label.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< -c -o $@

lvgl_src_lv_objx_lv_led.obj: $(SIMPLELINK_SDK_LVGL_PLUGIN_INSTALL_DIR)/source/third_party/lvgl/src/lv_objx/lv_led.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< -c -o $@

lvgl_src_lv_objx_lv_line.obj: $(SIMPLELINK_SDK_LVGL_PLUGIN_INSTALL_DIR)/source/third_party/lvgl/src/lv_objx/lv_line.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< -c -o $@

lvgl_src_lv_objx_lv_list.obj: $(SIMPLELINK_SDK_LVGL_PLUGIN_INSTALL_DIR)/source/third_party/lvgl/src/lv_objx/lv_list.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< -c -o $@

lvgl_src_lv_objx_lv_lmeter.obj: $(SIMPLELINK_SDK_LVGL_PLUGIN_INSTALL_DIR)/source/third_party/lvgl/src/lv_objx/lv_lmeter.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< -c -o $@

lvgl_src_lv_objx_lv_mbox.obj: $(SIMPLELINK_SDK_LVGL_PLUGIN_INSTALL_DIR)/source/third_party/lvgl/src/lv_objx/lv_mbox.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< -c -o $@

lvgl_src_lv_objx_lv_objx_templ.obj: $(SIMPLELINK_SDK_LVGL_PLUGIN_INSTALL_DIR)/source/third_party/lvgl/src/lv_objx/lv_objx_templ.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< -c -o $@

lvgl_src_lv_objx_lv_page.obj: $(SIMPLELINK_SDK_LVGL_PLUGIN_INSTALL_DIR)/source/third_party/lvgl/src/lv_objx/lv_page.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< -c -o $@

lvgl_src_lv_objx_lv_preload.obj: $(SIMPLELINK_SDK_LVGL_PLUGIN_INSTALL_DIR)/source/third_party/lvgl/src/lv_objx/lv_preload.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< -c -o $@

lvgl_src_lv_objx_lv_roller.obj: $(SIMPLELINK_SDK_LVGL_PLUGIN_INSTALL_DIR)/source/third_party/lvgl/src/lv_objx/lv_roller.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< -c -o $@

lvgl_src_lv_objx_lv_slider.obj: $(SIMPLELINK_SDK_LVGL_PLUGIN_INSTALL_DIR)/source/third_party/lvgl/src/lv_objx/lv_slider.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< -c -o $@

lvgl_src_lv_objx_lv_spinbox.obj: $(SIMPLELINK_SDK_LVGL_PLUGIN_INSTALL_DIR)/source/third_party/lvgl/src/lv_objx/lv_spinbox.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< -c -o $@

lvgl_src_lv_objx_lv_sw.obj: $(SIMPLELINK_SDK_LVGL_PLUGIN_INSTALL_DIR)/source/third_party/lvgl/src/lv_objx/lv_sw.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< -c -o $@

lvgl_src_lv_objx_lv_ta.obj: $(SIMPLELINK_SDK_LVGL_PLUGIN_INSTALL_DIR)/source/third_party/lvgl/src/lv_objx/lv_ta.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< -c -o $@

lvgl_src_lv_objx_lv_table.obj: $(SIMPLELINK_SDK_LVGL_PLUGIN_INSTALL_DIR)/source/third_party/lvgl/src/lv_objx/lv_table.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< -c -o $@

lvgl_src_lv_objx_lv_tabview.obj: $(SIMPLELINK_SDK_LVGL_PLUGIN_INSTALL_DIR)/source/third_party/lvgl/src/lv_objx/lv_tabview.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< -c -o $@

lvgl_src_lv_objx_lv_tileview.obj: $(SIMPLELINK_SDK_LVGL_PLUGIN_INSTALL_DIR)/source/third_party/lvgl/src/lv_objx/lv_tileview.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< -c -o $@

lvgl_src_lv_objx_lv_win.obj: $(SIMPLELINK_SDK_LVGL_PLUGIN_INSTALL_DIR)/source/third_party/lvgl/src/lv_objx/lv_win.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< -c -o $@

lvgl_src_lv_themes_lv_theme.obj: $(SIMPLELINK_SDK_LVGL_PLUGIN_INSTALL_DIR)/source/third_party/lvgl/src/lv_themes/lv_theme.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< -c -o $@

lvgl_src_lv_themes_lv_theme_alien.obj: $(SIMPLELINK_SDK_LVGL_PLUGIN_INSTALL_DIR)/source/third_party/lvgl/src/lv_themes/lv_theme_alien.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< -c -o $@

lvgl_src_lv_themes_lv_theme_default.obj: $(SIMPLELINK_SDK_LVGL_PLUGIN_INSTALL_DIR)/source/third_party/lvgl/src/lv_themes/lv_theme_default.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< -c -o $@

lvgl_src_lv_themes_lv_theme_material.obj: $(SIMPLELINK_SDK_LVGL_PLUGIN_INSTALL_DIR)/source/third_party/lvgl/src/lv_themes/lv_theme_material.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< -c -o $@

lvgl_src_lv_themes_lv_theme_mono.obj: $(SIMPLELINK_SDK_LVGL_PLUGIN_INSTALL_DIR)/source/third_party/lvgl/src/lv_themes/lv_theme_mono.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< -c -o $@

lvgl_src_lv_themes_lv_theme_nemo.obj: $(SIMPLELINK_SDK_LVGL_PLUGIN_INSTALL_DIR)/source/third_party/lvgl/src/lv_themes/lv_theme_nemo.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< -c -o $@

lvgl_src_lv_themes_lv_theme_night.obj: $(SIMPLELINK_SDK_LVGL_PLUGIN_INSTALL_DIR)/source/third_party/lvgl/src/lv_themes/lv_theme_night.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< -c -o $@

lvgl_src_lv_themes_lv_theme_templ.obj: $(SIMPLELINK_SDK_LVGL_PLUGIN_INSTALL_DIR)/source/third_party/lvgl/src/lv_themes/lv_theme_templ.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< -c -o $@

lvgl_src_lv_themes_lv_theme_zen.obj: $(SIMPLELINK_SDK_LVGL_PLUGIN_INSTALL_DIR)/source/third_party/lvgl/src/lv_themes/lv_theme_zen.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< -c -o $@

$(NAME).out: $(OBJECTS) $(KERNEL_BUILD)/gcc/freertos.lib
	@ echo linking $@
	@ $(LNK)  $(OBJECTS)  $(LFLAGS) -o $(NAME).out

clean:
	@ echo Cleaning...
	@ $(RM) $(OBJECTS) > $(DEVNULL) 2>&1
	@ $(RM) $(NAME).out > $(DEVNULL) 2>&1
	@ $(RM) $(NAME).map > $(DEVNULL) 2>&1
