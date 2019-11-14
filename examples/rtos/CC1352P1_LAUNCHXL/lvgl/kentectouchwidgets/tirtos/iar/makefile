SIMPLELINK_SDK_LVGL_PLUGIN_INSTALL_DIR ?= $(abspath ../../../../../../..)

include $(SIMPLELINK_SDK_LVGL_PLUGIN_INSTALL_DIR)/imports.mak

KERNEL_BUILD := $(SIMPLELINK_CC13X2_26X2_SDK_INSTALL_DIR)/kernel/tirtos/builds/CC1352P1_LAUNCHXL/release

CC = "$(IAR_ARMCOMPILER)/bin/iccarm"
LNK = "$(IAR_ARMCOMPILER)/bin/ilinkarm"

OBJECTS = kentectouchwidgets.obj ti_lvgl_ssd2119_disp.obj lv_port_indev.obj ti_lvgl_disp_interface.obj tirtos_main_tirtos.obj CC1352P1_LAUNCHXL.obj CC1352P1_LAUNCHXL_fxns.obj ccfg.obj lvgl_src_lv_core_lv_disp.obj lvgl_src_lv_core_lv_group.obj lvgl_src_lv_core_lv_indev.obj lvgl_src_lv_core_lv_obj.obj lvgl_src_lv_core_lv_refr.obj lvgl_src_lv_core_lv_style.obj lvgl_src_lv_draw_lv_draw.obj lvgl_src_lv_draw_lv_draw_arc.obj lvgl_src_lv_draw_lv_draw_basic.obj lvgl_src_lv_draw_lv_draw_img.obj lvgl_src_lv_draw_lv_draw_label.obj lvgl_src_lv_draw_lv_draw_line.obj lvgl_src_lv_draw_lv_draw_rect.obj lvgl_src_lv_draw_lv_draw_triangle.obj lvgl_src_lv_draw_lv_img_cache.obj lvgl_src_lv_draw_lv_img_decoder.obj lvgl_src_lv_font_lv_font.obj lvgl_src_lv_font_lv_font_fmt_txt.obj lvgl_src_lv_font_lv_font_roboto_12.obj lvgl_src_lv_font_lv_font_roboto_16.obj lvgl_src_lv_font_lv_font_roboto_22.obj lvgl_src_lv_font_lv_font_roboto_28.obj lvgl_src_lv_font_lv_font_unscii_8.obj lvgl_src_lv_hal_lv_hal_disp.obj lvgl_src_lv_hal_lv_hal_indev.obj lvgl_src_lv_hal_lv_hal_tick.obj lvgl_src_lv_misc_lv_anim.obj lvgl_src_lv_misc_lv_area.obj lvgl_src_lv_misc_lv_async.obj lvgl_src_lv_misc_lv_circ.obj lvgl_src_lv_misc_lv_color.obj lvgl_src_lv_misc_lv_fs.obj lvgl_src_lv_misc_lv_gc.obj lvgl_src_lv_misc_lv_ll.obj lvgl_src_lv_misc_lv_log.obj lvgl_src_lv_misc_lv_math.obj lvgl_src_lv_misc_lv_mem.obj lvgl_src_lv_misc_lv_task.obj lvgl_src_lv_misc_lv_templ.obj lvgl_src_lv_misc_lv_txt.obj lvgl_src_lv_misc_lv_utils.obj lvgl_src_lv_objx_lv_arc.obj lvgl_src_lv_objx_lv_bar.obj lvgl_src_lv_objx_lv_btn.obj lvgl_src_lv_objx_lv_btnm.obj lvgl_src_lv_objx_lv_calendar.obj lvgl_src_lv_objx_lv_canvas.obj lvgl_src_lv_objx_lv_cb.obj lvgl_src_lv_objx_lv_chart.obj lvgl_src_lv_objx_lv_cont.obj lvgl_src_lv_objx_lv_ddlist.obj lvgl_src_lv_objx_lv_gauge.obj lvgl_src_lv_objx_lv_img.obj lvgl_src_lv_objx_lv_imgbtn.obj lvgl_src_lv_objx_lv_kb.obj lvgl_src_lv_objx_lv_label.obj lvgl_src_lv_objx_lv_led.obj lvgl_src_lv_objx_lv_line.obj lvgl_src_lv_objx_lv_list.obj lvgl_src_lv_objx_lv_lmeter.obj lvgl_src_lv_objx_lv_mbox.obj lvgl_src_lv_objx_lv_objx_templ.obj lvgl_src_lv_objx_lv_page.obj lvgl_src_lv_objx_lv_preload.obj lvgl_src_lv_objx_lv_roller.obj lvgl_src_lv_objx_lv_slider.obj lvgl_src_lv_objx_lv_spinbox.obj lvgl_src_lv_objx_lv_sw.obj lvgl_src_lv_objx_lv_ta.obj lvgl_src_lv_objx_lv_table.obj lvgl_src_lv_objx_lv_tabview.obj lvgl_src_lv_objx_lv_tileview.obj lvgl_src_lv_objx_lv_win.obj lvgl_src_lv_themes_lv_theme.obj lvgl_src_lv_themes_lv_theme_alien.obj lvgl_src_lv_themes_lv_theme_default.obj lvgl_src_lv_themes_lv_theme_material.obj lvgl_src_lv_themes_lv_theme_mono.obj lvgl_src_lv_themes_lv_theme_nemo.obj lvgl_src_lv_themes_lv_theme_night.obj lvgl_src_lv_themes_lv_theme_templ.obj lvgl_src_lv_themes_lv_theme_zen.obj

CONFIGPKG = $(KERNEL_BUILD)/iar

NAME = kentectouchwidgets

CFLAGS = -I../.. \
    -DDeviceFamily_CC13X2 \
    "-I$(SIMPLELINK_CC13X2_26X2_SDK_INSTALL_DIR)/source" \
    -DLV_CONF_INCLUDE_SIMPLE \
    "-I$(SIMPLELINK_SDK_LVGL_PLUGIN_INSTALL_DIR)/source" \
    "-I$(SIMPLELINK_SDK_LVGL_PLUGIN_INSTALL_DIR)/source/third_party" \
    "-I$(SIMPLELINK_SDK_LVGL_PLUGIN_INSTALL_DIR)/source/third_party/lvgl" \
    "-I$(SIMPLELINK_CC13X2_26X2_SDK_INSTALL_DIR)/source/ti/posix/iar" \
    --debug \
    --silent \
    -e \
    --aeabi \
    --thumb \
    --diag_suppress=Pa050

LFLAGS = "$(SIMPLELINK_CC13X2_26X2_SDK_INSTALL_DIR)/source/ti/display/lib/display.arm4f" \
    "$(SIMPLELINK_CC13X2_26X2_SDK_INSTALL_DIR)/source/ti/grlib/lib/iar/m4f/grlib.a" \
    "$(SIMPLELINK_CC13X2_26X2_SDK_INSTALL_DIR)/source/third_party/spiffs/lib/iar/m4f/spiffs_cc26xx.a" \
    "$(SIMPLELINK_CC13X2_26X2_SDK_INSTALL_DIR)/source/ti/drivers/lib/drivers_cc13x2.arm4f" \
    "$(SIMPLELINK_CC13X2_26X2_SDK_INSTALL_DIR)/kernel/tirtos/packages/ti/dpl/lib/dpl_cc13x2.arm4f" \
    -f "$(KERNEL_BUILD)/iar/linker.cmd" \
    "$(SIMPLELINK_CC13X2_26X2_SDK_INSTALL_DIR)/source/ti/devices/cc13x2_cc26x2/driverlib/bin/iar/driverlib.lib" \
    --config ../../tirtos/iar/CC1352P1_LAUNCHXL_TIRTOS.icf \
    --map "$(NAME).map" \
    --silent \
    --cpu=Cortex-M4F \
    --semihosting=iar_breakpoint

all: $(NAME).out

$(CONFIGPKG)/linker.cmd $(CONFIGPKG)/compiler.opt:
	@ $(ECHOBLANKLINE)
	@ echo $(CONFIGPKG) is not built.
	@ echo You can build it by issuing $(MAKE) in $(CONFIGPKG).
	@ $(ECHOBLANKLINE)

kentectouchwidgets.obj: ../../kentectouchwidgets.c $(CONFIGPKG)/compiler.opt
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< -f $(CONFIGPKG)/compiler.opt -o $@

ti_lvgl_ssd2119_disp.obj: ../../ti_lvgl_ssd2119_disp.c $(CONFIGPKG)/compiler.opt
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< -f $(CONFIGPKG)/compiler.opt -o $@

lv_port_indev.obj: ../../lv_port_indev.c $(CONFIGPKG)/compiler.opt
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< -f $(CONFIGPKG)/compiler.opt -o $@

ti_lvgl_disp_interface.obj: ../../ti_lvgl_disp_interface.c $(CONFIGPKG)/compiler.opt
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< -f $(CONFIGPKG)/compiler.opt -o $@

tirtos_main_tirtos.obj: ../../tirtos/main_tirtos.c $(CONFIGPKG)/compiler.opt
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< -f $(CONFIGPKG)/compiler.opt -o $@

CC1352P1_LAUNCHXL.obj: ../../CC1352P1_LAUNCHXL.c $(CONFIGPKG)/compiler.opt
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< -f $(CONFIGPKG)/compiler.opt -o $@

CC1352P1_LAUNCHXL_fxns.obj: ../../CC1352P1_LAUNCHXL_fxns.c $(CONFIGPKG)/compiler.opt
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< -f $(CONFIGPKG)/compiler.opt -o $@

ccfg.obj: ../../ccfg.c $(CONFIGPKG)/compiler.opt
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< -f $(CONFIGPKG)/compiler.opt -o $@

lvgl_src_lv_core_lv_disp.obj: $(SIMPLELINK_SDK_LVGL_PLUGIN_INSTALL_DIR)/source/third_party/lvgl/src/lv_core/lv_disp.c $(CONFIGPKG)/compiler.opt
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< -f $(CONFIGPKG)/compiler.opt -o $@

lvgl_src_lv_core_lv_group.obj: $(SIMPLELINK_SDK_LVGL_PLUGIN_INSTALL_DIR)/source/third_party/lvgl/src/lv_core/lv_group.c $(CONFIGPKG)/compiler.opt
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< -f $(CONFIGPKG)/compiler.opt -o $@

lvgl_src_lv_core_lv_indev.obj: $(SIMPLELINK_SDK_LVGL_PLUGIN_INSTALL_DIR)/source/third_party/lvgl/src/lv_core/lv_indev.c $(CONFIGPKG)/compiler.opt
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< -f $(CONFIGPKG)/compiler.opt -o $@

lvgl_src_lv_core_lv_obj.obj: $(SIMPLELINK_SDK_LVGL_PLUGIN_INSTALL_DIR)/source/third_party/lvgl/src/lv_core/lv_obj.c $(CONFIGPKG)/compiler.opt
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< -f $(CONFIGPKG)/compiler.opt -o $@

lvgl_src_lv_core_lv_refr.obj: $(SIMPLELINK_SDK_LVGL_PLUGIN_INSTALL_DIR)/source/third_party/lvgl/src/lv_core/lv_refr.c $(CONFIGPKG)/compiler.opt
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< -f $(CONFIGPKG)/compiler.opt -o $@

lvgl_src_lv_core_lv_style.obj: $(SIMPLELINK_SDK_LVGL_PLUGIN_INSTALL_DIR)/source/third_party/lvgl/src/lv_core/lv_style.c $(CONFIGPKG)/compiler.opt
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< -f $(CONFIGPKG)/compiler.opt -o $@

lvgl_src_lv_draw_lv_draw.obj: $(SIMPLELINK_SDK_LVGL_PLUGIN_INSTALL_DIR)/source/third_party/lvgl/src/lv_draw/lv_draw.c $(CONFIGPKG)/compiler.opt
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< -f $(CONFIGPKG)/compiler.opt -o $@

lvgl_src_lv_draw_lv_draw_arc.obj: $(SIMPLELINK_SDK_LVGL_PLUGIN_INSTALL_DIR)/source/third_party/lvgl/src/lv_draw/lv_draw_arc.c $(CONFIGPKG)/compiler.opt
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< -f $(CONFIGPKG)/compiler.opt -o $@

lvgl_src_lv_draw_lv_draw_basic.obj: $(SIMPLELINK_SDK_LVGL_PLUGIN_INSTALL_DIR)/source/third_party/lvgl/src/lv_draw/lv_draw_basic.c $(CONFIGPKG)/compiler.opt
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< -f $(CONFIGPKG)/compiler.opt -o $@

lvgl_src_lv_draw_lv_draw_img.obj: $(SIMPLELINK_SDK_LVGL_PLUGIN_INSTALL_DIR)/source/third_party/lvgl/src/lv_draw/lv_draw_img.c $(CONFIGPKG)/compiler.opt
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< -f $(CONFIGPKG)/compiler.opt -o $@

lvgl_src_lv_draw_lv_draw_label.obj: $(SIMPLELINK_SDK_LVGL_PLUGIN_INSTALL_DIR)/source/third_party/lvgl/src/lv_draw/lv_draw_label.c $(CONFIGPKG)/compiler.opt
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< -f $(CONFIGPKG)/compiler.opt -o $@

lvgl_src_lv_draw_lv_draw_line.obj: $(SIMPLELINK_SDK_LVGL_PLUGIN_INSTALL_DIR)/source/third_party/lvgl/src/lv_draw/lv_draw_line.c $(CONFIGPKG)/compiler.opt
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< -f $(CONFIGPKG)/compiler.opt -o $@

lvgl_src_lv_draw_lv_draw_rect.obj: $(SIMPLELINK_SDK_LVGL_PLUGIN_INSTALL_DIR)/source/third_party/lvgl/src/lv_draw/lv_draw_rect.c $(CONFIGPKG)/compiler.opt
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< -f $(CONFIGPKG)/compiler.opt -o $@

lvgl_src_lv_draw_lv_draw_triangle.obj: $(SIMPLELINK_SDK_LVGL_PLUGIN_INSTALL_DIR)/source/third_party/lvgl/src/lv_draw/lv_draw_triangle.c $(CONFIGPKG)/compiler.opt
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< -f $(CONFIGPKG)/compiler.opt -o $@

lvgl_src_lv_draw_lv_img_cache.obj: $(SIMPLELINK_SDK_LVGL_PLUGIN_INSTALL_DIR)/source/third_party/lvgl/src/lv_draw/lv_img_cache.c $(CONFIGPKG)/compiler.opt
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< -f $(CONFIGPKG)/compiler.opt -o $@

lvgl_src_lv_draw_lv_img_decoder.obj: $(SIMPLELINK_SDK_LVGL_PLUGIN_INSTALL_DIR)/source/third_party/lvgl/src/lv_draw/lv_img_decoder.c $(CONFIGPKG)/compiler.opt
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< -f $(CONFIGPKG)/compiler.opt -o $@

lvgl_src_lv_font_lv_font.obj: $(SIMPLELINK_SDK_LVGL_PLUGIN_INSTALL_DIR)/source/third_party/lvgl/src/lv_font/lv_font.c $(CONFIGPKG)/compiler.opt
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< -f $(CONFIGPKG)/compiler.opt -o $@

lvgl_src_lv_font_lv_font_fmt_txt.obj: $(SIMPLELINK_SDK_LVGL_PLUGIN_INSTALL_DIR)/source/third_party/lvgl/src/lv_font/lv_font_fmt_txt.c $(CONFIGPKG)/compiler.opt
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< -f $(CONFIGPKG)/compiler.opt -o $@

lvgl_src_lv_font_lv_font_roboto_12.obj: $(SIMPLELINK_SDK_LVGL_PLUGIN_INSTALL_DIR)/source/third_party/lvgl/src/lv_font/lv_font_roboto_12.c $(CONFIGPKG)/compiler.opt
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< -f $(CONFIGPKG)/compiler.opt -o $@

lvgl_src_lv_font_lv_font_roboto_16.obj: $(SIMPLELINK_SDK_LVGL_PLUGIN_INSTALL_DIR)/source/third_party/lvgl/src/lv_font/lv_font_roboto_16.c $(CONFIGPKG)/compiler.opt
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< -f $(CONFIGPKG)/compiler.opt -o $@

lvgl_src_lv_font_lv_font_roboto_22.obj: $(SIMPLELINK_SDK_LVGL_PLUGIN_INSTALL_DIR)/source/third_party/lvgl/src/lv_font/lv_font_roboto_22.c $(CONFIGPKG)/compiler.opt
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< -f $(CONFIGPKG)/compiler.opt -o $@

lvgl_src_lv_font_lv_font_roboto_28.obj: $(SIMPLELINK_SDK_LVGL_PLUGIN_INSTALL_DIR)/source/third_party/lvgl/src/lv_font/lv_font_roboto_28.c $(CONFIGPKG)/compiler.opt
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< -f $(CONFIGPKG)/compiler.opt -o $@

lvgl_src_lv_font_lv_font_unscii_8.obj: $(SIMPLELINK_SDK_LVGL_PLUGIN_INSTALL_DIR)/source/third_party/lvgl/src/lv_font/lv_font_unscii_8.c $(CONFIGPKG)/compiler.opt
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< -f $(CONFIGPKG)/compiler.opt -o $@

lvgl_src_lv_hal_lv_hal_disp.obj: $(SIMPLELINK_SDK_LVGL_PLUGIN_INSTALL_DIR)/source/third_party/lvgl/src/lv_hal/lv_hal_disp.c $(CONFIGPKG)/compiler.opt
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< -f $(CONFIGPKG)/compiler.opt -o $@

lvgl_src_lv_hal_lv_hal_indev.obj: $(SIMPLELINK_SDK_LVGL_PLUGIN_INSTALL_DIR)/source/third_party/lvgl/src/lv_hal/lv_hal_indev.c $(CONFIGPKG)/compiler.opt
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< -f $(CONFIGPKG)/compiler.opt -o $@

lvgl_src_lv_hal_lv_hal_tick.obj: $(SIMPLELINK_SDK_LVGL_PLUGIN_INSTALL_DIR)/source/third_party/lvgl/src/lv_hal/lv_hal_tick.c $(CONFIGPKG)/compiler.opt
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< -f $(CONFIGPKG)/compiler.opt -o $@

lvgl_src_lv_misc_lv_anim.obj: $(SIMPLELINK_SDK_LVGL_PLUGIN_INSTALL_DIR)/source/third_party/lvgl/src/lv_misc/lv_anim.c $(CONFIGPKG)/compiler.opt
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< -f $(CONFIGPKG)/compiler.opt -o $@

lvgl_src_lv_misc_lv_area.obj: $(SIMPLELINK_SDK_LVGL_PLUGIN_INSTALL_DIR)/source/third_party/lvgl/src/lv_misc/lv_area.c $(CONFIGPKG)/compiler.opt
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< -f $(CONFIGPKG)/compiler.opt -o $@

lvgl_src_lv_misc_lv_async.obj: $(SIMPLELINK_SDK_LVGL_PLUGIN_INSTALL_DIR)/source/third_party/lvgl/src/lv_misc/lv_async.c $(CONFIGPKG)/compiler.opt
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< -f $(CONFIGPKG)/compiler.opt -o $@

lvgl_src_lv_misc_lv_circ.obj: $(SIMPLELINK_SDK_LVGL_PLUGIN_INSTALL_DIR)/source/third_party/lvgl/src/lv_misc/lv_circ.c $(CONFIGPKG)/compiler.opt
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< -f $(CONFIGPKG)/compiler.opt -o $@

lvgl_src_lv_misc_lv_color.obj: $(SIMPLELINK_SDK_LVGL_PLUGIN_INSTALL_DIR)/source/third_party/lvgl/src/lv_misc/lv_color.c $(CONFIGPKG)/compiler.opt
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< -f $(CONFIGPKG)/compiler.opt -o $@

lvgl_src_lv_misc_lv_fs.obj: $(SIMPLELINK_SDK_LVGL_PLUGIN_INSTALL_DIR)/source/third_party/lvgl/src/lv_misc/lv_fs.c $(CONFIGPKG)/compiler.opt
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< -f $(CONFIGPKG)/compiler.opt -o $@

lvgl_src_lv_misc_lv_gc.obj: $(SIMPLELINK_SDK_LVGL_PLUGIN_INSTALL_DIR)/source/third_party/lvgl/src/lv_misc/lv_gc.c $(CONFIGPKG)/compiler.opt
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< -f $(CONFIGPKG)/compiler.opt -o $@

lvgl_src_lv_misc_lv_ll.obj: $(SIMPLELINK_SDK_LVGL_PLUGIN_INSTALL_DIR)/source/third_party/lvgl/src/lv_misc/lv_ll.c $(CONFIGPKG)/compiler.opt
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< -f $(CONFIGPKG)/compiler.opt -o $@

lvgl_src_lv_misc_lv_log.obj: $(SIMPLELINK_SDK_LVGL_PLUGIN_INSTALL_DIR)/source/third_party/lvgl/src/lv_misc/lv_log.c $(CONFIGPKG)/compiler.opt
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< -f $(CONFIGPKG)/compiler.opt -o $@

lvgl_src_lv_misc_lv_math.obj: $(SIMPLELINK_SDK_LVGL_PLUGIN_INSTALL_DIR)/source/third_party/lvgl/src/lv_misc/lv_math.c $(CONFIGPKG)/compiler.opt
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< -f $(CONFIGPKG)/compiler.opt -o $@

lvgl_src_lv_misc_lv_mem.obj: $(SIMPLELINK_SDK_LVGL_PLUGIN_INSTALL_DIR)/source/third_party/lvgl/src/lv_misc/lv_mem.c $(CONFIGPKG)/compiler.opt
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< -f $(CONFIGPKG)/compiler.opt -o $@

lvgl_src_lv_misc_lv_task.obj: $(SIMPLELINK_SDK_LVGL_PLUGIN_INSTALL_DIR)/source/third_party/lvgl/src/lv_misc/lv_task.c $(CONFIGPKG)/compiler.opt
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< -f $(CONFIGPKG)/compiler.opt -o $@

lvgl_src_lv_misc_lv_templ.obj: $(SIMPLELINK_SDK_LVGL_PLUGIN_INSTALL_DIR)/source/third_party/lvgl/src/lv_misc/lv_templ.c $(CONFIGPKG)/compiler.opt
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< -f $(CONFIGPKG)/compiler.opt -o $@

lvgl_src_lv_misc_lv_txt.obj: $(SIMPLELINK_SDK_LVGL_PLUGIN_INSTALL_DIR)/source/third_party/lvgl/src/lv_misc/lv_txt.c $(CONFIGPKG)/compiler.opt
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< -f $(CONFIGPKG)/compiler.opt -o $@

lvgl_src_lv_misc_lv_utils.obj: $(SIMPLELINK_SDK_LVGL_PLUGIN_INSTALL_DIR)/source/third_party/lvgl/src/lv_misc/lv_utils.c $(CONFIGPKG)/compiler.opt
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< -f $(CONFIGPKG)/compiler.opt -o $@

lvgl_src_lv_objx_lv_arc.obj: $(SIMPLELINK_SDK_LVGL_PLUGIN_INSTALL_DIR)/source/third_party/lvgl/src/lv_objx/lv_arc.c $(CONFIGPKG)/compiler.opt
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< -f $(CONFIGPKG)/compiler.opt -o $@

lvgl_src_lv_objx_lv_bar.obj: $(SIMPLELINK_SDK_LVGL_PLUGIN_INSTALL_DIR)/source/third_party/lvgl/src/lv_objx/lv_bar.c $(CONFIGPKG)/compiler.opt
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< -f $(CONFIGPKG)/compiler.opt -o $@

lvgl_src_lv_objx_lv_btn.obj: $(SIMPLELINK_SDK_LVGL_PLUGIN_INSTALL_DIR)/source/third_party/lvgl/src/lv_objx/lv_btn.c $(CONFIGPKG)/compiler.opt
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< -f $(CONFIGPKG)/compiler.opt -o $@

lvgl_src_lv_objx_lv_btnm.obj: $(SIMPLELINK_SDK_LVGL_PLUGIN_INSTALL_DIR)/source/third_party/lvgl/src/lv_objx/lv_btnm.c $(CONFIGPKG)/compiler.opt
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< -f $(CONFIGPKG)/compiler.opt -o $@

lvgl_src_lv_objx_lv_calendar.obj: $(SIMPLELINK_SDK_LVGL_PLUGIN_INSTALL_DIR)/source/third_party/lvgl/src/lv_objx/lv_calendar.c $(CONFIGPKG)/compiler.opt
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< -f $(CONFIGPKG)/compiler.opt -o $@

lvgl_src_lv_objx_lv_canvas.obj: $(SIMPLELINK_SDK_LVGL_PLUGIN_INSTALL_DIR)/source/third_party/lvgl/src/lv_objx/lv_canvas.c $(CONFIGPKG)/compiler.opt
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< -f $(CONFIGPKG)/compiler.opt -o $@

lvgl_src_lv_objx_lv_cb.obj: $(SIMPLELINK_SDK_LVGL_PLUGIN_INSTALL_DIR)/source/third_party/lvgl/src/lv_objx/lv_cb.c $(CONFIGPKG)/compiler.opt
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< -f $(CONFIGPKG)/compiler.opt -o $@

lvgl_src_lv_objx_lv_chart.obj: $(SIMPLELINK_SDK_LVGL_PLUGIN_INSTALL_DIR)/source/third_party/lvgl/src/lv_objx/lv_chart.c $(CONFIGPKG)/compiler.opt
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< -f $(CONFIGPKG)/compiler.opt -o $@

lvgl_src_lv_objx_lv_cont.obj: $(SIMPLELINK_SDK_LVGL_PLUGIN_INSTALL_DIR)/source/third_party/lvgl/src/lv_objx/lv_cont.c $(CONFIGPKG)/compiler.opt
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< -f $(CONFIGPKG)/compiler.opt -o $@

lvgl_src_lv_objx_lv_ddlist.obj: $(SIMPLELINK_SDK_LVGL_PLUGIN_INSTALL_DIR)/source/third_party/lvgl/src/lv_objx/lv_ddlist.c $(CONFIGPKG)/compiler.opt
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< -f $(CONFIGPKG)/compiler.opt -o $@

lvgl_src_lv_objx_lv_gauge.obj: $(SIMPLELINK_SDK_LVGL_PLUGIN_INSTALL_DIR)/source/third_party/lvgl/src/lv_objx/lv_gauge.c $(CONFIGPKG)/compiler.opt
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< -f $(CONFIGPKG)/compiler.opt -o $@

lvgl_src_lv_objx_lv_img.obj: $(SIMPLELINK_SDK_LVGL_PLUGIN_INSTALL_DIR)/source/third_party/lvgl/src/lv_objx/lv_img.c $(CONFIGPKG)/compiler.opt
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< -f $(CONFIGPKG)/compiler.opt -o $@

lvgl_src_lv_objx_lv_imgbtn.obj: $(SIMPLELINK_SDK_LVGL_PLUGIN_INSTALL_DIR)/source/third_party/lvgl/src/lv_objx/lv_imgbtn.c $(CONFIGPKG)/compiler.opt
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< -f $(CONFIGPKG)/compiler.opt -o $@

lvgl_src_lv_objx_lv_kb.obj: $(SIMPLELINK_SDK_LVGL_PLUGIN_INSTALL_DIR)/source/third_party/lvgl/src/lv_objx/lv_kb.c $(CONFIGPKG)/compiler.opt
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< -f $(CONFIGPKG)/compiler.opt -o $@

lvgl_src_lv_objx_lv_label.obj: $(SIMPLELINK_SDK_LVGL_PLUGIN_INSTALL_DIR)/source/third_party/lvgl/src/lv_objx/lv_label.c $(CONFIGPKG)/compiler.opt
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< -f $(CONFIGPKG)/compiler.opt -o $@

lvgl_src_lv_objx_lv_led.obj: $(SIMPLELINK_SDK_LVGL_PLUGIN_INSTALL_DIR)/source/third_party/lvgl/src/lv_objx/lv_led.c $(CONFIGPKG)/compiler.opt
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< -f $(CONFIGPKG)/compiler.opt -o $@

lvgl_src_lv_objx_lv_line.obj: $(SIMPLELINK_SDK_LVGL_PLUGIN_INSTALL_DIR)/source/third_party/lvgl/src/lv_objx/lv_line.c $(CONFIGPKG)/compiler.opt
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< -f $(CONFIGPKG)/compiler.opt -o $@

lvgl_src_lv_objx_lv_list.obj: $(SIMPLELINK_SDK_LVGL_PLUGIN_INSTALL_DIR)/source/third_party/lvgl/src/lv_objx/lv_list.c $(CONFIGPKG)/compiler.opt
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< -f $(CONFIGPKG)/compiler.opt -o $@

lvgl_src_lv_objx_lv_lmeter.obj: $(SIMPLELINK_SDK_LVGL_PLUGIN_INSTALL_DIR)/source/third_party/lvgl/src/lv_objx/lv_lmeter.c $(CONFIGPKG)/compiler.opt
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< -f $(CONFIGPKG)/compiler.opt -o $@

lvgl_src_lv_objx_lv_mbox.obj: $(SIMPLELINK_SDK_LVGL_PLUGIN_INSTALL_DIR)/source/third_party/lvgl/src/lv_objx/lv_mbox.c $(CONFIGPKG)/compiler.opt
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< -f $(CONFIGPKG)/compiler.opt -o $@

lvgl_src_lv_objx_lv_objx_templ.obj: $(SIMPLELINK_SDK_LVGL_PLUGIN_INSTALL_DIR)/source/third_party/lvgl/src/lv_objx/lv_objx_templ.c $(CONFIGPKG)/compiler.opt
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< -f $(CONFIGPKG)/compiler.opt -o $@

lvgl_src_lv_objx_lv_page.obj: $(SIMPLELINK_SDK_LVGL_PLUGIN_INSTALL_DIR)/source/third_party/lvgl/src/lv_objx/lv_page.c $(CONFIGPKG)/compiler.opt
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< -f $(CONFIGPKG)/compiler.opt -o $@

lvgl_src_lv_objx_lv_preload.obj: $(SIMPLELINK_SDK_LVGL_PLUGIN_INSTALL_DIR)/source/third_party/lvgl/src/lv_objx/lv_preload.c $(CONFIGPKG)/compiler.opt
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< -f $(CONFIGPKG)/compiler.opt -o $@

lvgl_src_lv_objx_lv_roller.obj: $(SIMPLELINK_SDK_LVGL_PLUGIN_INSTALL_DIR)/source/third_party/lvgl/src/lv_objx/lv_roller.c $(CONFIGPKG)/compiler.opt
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< -f $(CONFIGPKG)/compiler.opt -o $@

lvgl_src_lv_objx_lv_slider.obj: $(SIMPLELINK_SDK_LVGL_PLUGIN_INSTALL_DIR)/source/third_party/lvgl/src/lv_objx/lv_slider.c $(CONFIGPKG)/compiler.opt
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< -f $(CONFIGPKG)/compiler.opt -o $@

lvgl_src_lv_objx_lv_spinbox.obj: $(SIMPLELINK_SDK_LVGL_PLUGIN_INSTALL_DIR)/source/third_party/lvgl/src/lv_objx/lv_spinbox.c $(CONFIGPKG)/compiler.opt
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< -f $(CONFIGPKG)/compiler.opt -o $@

lvgl_src_lv_objx_lv_sw.obj: $(SIMPLELINK_SDK_LVGL_PLUGIN_INSTALL_DIR)/source/third_party/lvgl/src/lv_objx/lv_sw.c $(CONFIGPKG)/compiler.opt
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< -f $(CONFIGPKG)/compiler.opt -o $@

lvgl_src_lv_objx_lv_ta.obj: $(SIMPLELINK_SDK_LVGL_PLUGIN_INSTALL_DIR)/source/third_party/lvgl/src/lv_objx/lv_ta.c $(CONFIGPKG)/compiler.opt
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< -f $(CONFIGPKG)/compiler.opt -o $@

lvgl_src_lv_objx_lv_table.obj: $(SIMPLELINK_SDK_LVGL_PLUGIN_INSTALL_DIR)/source/third_party/lvgl/src/lv_objx/lv_table.c $(CONFIGPKG)/compiler.opt
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< -f $(CONFIGPKG)/compiler.opt -o $@

lvgl_src_lv_objx_lv_tabview.obj: $(SIMPLELINK_SDK_LVGL_PLUGIN_INSTALL_DIR)/source/third_party/lvgl/src/lv_objx/lv_tabview.c $(CONFIGPKG)/compiler.opt
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< -f $(CONFIGPKG)/compiler.opt -o $@

lvgl_src_lv_objx_lv_tileview.obj: $(SIMPLELINK_SDK_LVGL_PLUGIN_INSTALL_DIR)/source/third_party/lvgl/src/lv_objx/lv_tileview.c $(CONFIGPKG)/compiler.opt
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< -f $(CONFIGPKG)/compiler.opt -o $@

lvgl_src_lv_objx_lv_win.obj: $(SIMPLELINK_SDK_LVGL_PLUGIN_INSTALL_DIR)/source/third_party/lvgl/src/lv_objx/lv_win.c $(CONFIGPKG)/compiler.opt
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< -f $(CONFIGPKG)/compiler.opt -o $@

lvgl_src_lv_themes_lv_theme.obj: $(SIMPLELINK_SDK_LVGL_PLUGIN_INSTALL_DIR)/source/third_party/lvgl/src/lv_themes/lv_theme.c $(CONFIGPKG)/compiler.opt
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< -f $(CONFIGPKG)/compiler.opt -o $@

lvgl_src_lv_themes_lv_theme_alien.obj: $(SIMPLELINK_SDK_LVGL_PLUGIN_INSTALL_DIR)/source/third_party/lvgl/src/lv_themes/lv_theme_alien.c $(CONFIGPKG)/compiler.opt
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< -f $(CONFIGPKG)/compiler.opt -o $@

lvgl_src_lv_themes_lv_theme_default.obj: $(SIMPLELINK_SDK_LVGL_PLUGIN_INSTALL_DIR)/source/third_party/lvgl/src/lv_themes/lv_theme_default.c $(CONFIGPKG)/compiler.opt
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< -f $(CONFIGPKG)/compiler.opt -o $@

lvgl_src_lv_themes_lv_theme_material.obj: $(SIMPLELINK_SDK_LVGL_PLUGIN_INSTALL_DIR)/source/third_party/lvgl/src/lv_themes/lv_theme_material.c $(CONFIGPKG)/compiler.opt
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< -f $(CONFIGPKG)/compiler.opt -o $@

lvgl_src_lv_themes_lv_theme_mono.obj: $(SIMPLELINK_SDK_LVGL_PLUGIN_INSTALL_DIR)/source/third_party/lvgl/src/lv_themes/lv_theme_mono.c $(CONFIGPKG)/compiler.opt
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< -f $(CONFIGPKG)/compiler.opt -o $@

lvgl_src_lv_themes_lv_theme_nemo.obj: $(SIMPLELINK_SDK_LVGL_PLUGIN_INSTALL_DIR)/source/third_party/lvgl/src/lv_themes/lv_theme_nemo.c $(CONFIGPKG)/compiler.opt
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< -f $(CONFIGPKG)/compiler.opt -o $@

lvgl_src_lv_themes_lv_theme_night.obj: $(SIMPLELINK_SDK_LVGL_PLUGIN_INSTALL_DIR)/source/third_party/lvgl/src/lv_themes/lv_theme_night.c $(CONFIGPKG)/compiler.opt
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< -f $(CONFIGPKG)/compiler.opt -o $@

lvgl_src_lv_themes_lv_theme_templ.obj: $(SIMPLELINK_SDK_LVGL_PLUGIN_INSTALL_DIR)/source/third_party/lvgl/src/lv_themes/lv_theme_templ.c $(CONFIGPKG)/compiler.opt
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< -f $(CONFIGPKG)/compiler.opt -o $@

lvgl_src_lv_themes_lv_theme_zen.obj: $(SIMPLELINK_SDK_LVGL_PLUGIN_INSTALL_DIR)/source/third_party/lvgl/src/lv_themes/lv_theme_zen.c $(CONFIGPKG)/compiler.opt
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< -f $(CONFIGPKG)/compiler.opt -o $@

$(NAME).out: $(OBJECTS) $(CONFIGPKG)/linker.cmd
	@ echo linking $@
	@ $(LNK)  $(OBJECTS)  $(LFLAGS) -o $(NAME).out

clean:
	@ echo Cleaning...
	@ $(RM) $(OBJECTS) > $(DEVNULL) 2>&1
	@ $(RM) $(NAME).out > $(DEVNULL) 2>&1
	@ $(RM) $(NAME).map > $(DEVNULL) 2>&1
