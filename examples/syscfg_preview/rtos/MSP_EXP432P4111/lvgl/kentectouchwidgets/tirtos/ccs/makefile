SIMPLELINK_SDK_LVGL_PLUGIN_INSTALL_DIR ?= $(abspath ../../../../../../../..)

include $(SIMPLELINK_SDK_LVGL_PLUGIN_INSTALL_DIR)/imports.mak

KERNEL_BUILD := $(SIMPLELINK_MSP432_SDK_INSTALL_DIR)/kernel/tirtos/builds/MSP_EXP432P4111/release

CC = "$(CCS_ARMCOMPILER)/bin/armcl"
LNK = "$(CCS_ARMCOMPILER)/bin/armcl"

OBJECTS = kentectouchwidgets.obj Board.obj ti_lvgl_ssd2119_disp.obj lv_port_indev.obj ti_lvgl_disp_interface.obj tirtos_main_tirtos.obj lvgl_src_lv_core_lv_disp.obj lvgl_src_lv_core_lv_group.obj lvgl_src_lv_core_lv_indev.obj lvgl_src_lv_core_lv_obj.obj lvgl_src_lv_core_lv_refr.obj lvgl_src_lv_core_lv_style.obj lvgl_src_lv_draw_lv_draw.obj lvgl_src_lv_draw_lv_draw_arc.obj lvgl_src_lv_draw_lv_draw_basic.obj lvgl_src_lv_draw_lv_draw_img.obj lvgl_src_lv_draw_lv_draw_label.obj lvgl_src_lv_draw_lv_draw_line.obj lvgl_src_lv_draw_lv_draw_rect.obj lvgl_src_lv_draw_lv_draw_triangle.obj lvgl_src_lv_draw_lv_img_cache.obj lvgl_src_lv_draw_lv_img_decoder.obj lvgl_src_lv_font_lv_font.obj lvgl_src_lv_font_lv_font_fmt_txt.obj lvgl_src_lv_font_lv_font_roboto_12.obj lvgl_src_lv_font_lv_font_roboto_16.obj lvgl_src_lv_font_lv_font_roboto_22.obj lvgl_src_lv_font_lv_font_roboto_28.obj lvgl_src_lv_font_lv_font_unscii_8.obj lvgl_src_lv_hal_lv_hal_disp.obj lvgl_src_lv_hal_lv_hal_indev.obj lvgl_src_lv_hal_lv_hal_tick.obj lvgl_src_lv_misc_lv_anim.obj lvgl_src_lv_misc_lv_area.obj lvgl_src_lv_misc_lv_async.obj lvgl_src_lv_misc_lv_circ.obj lvgl_src_lv_misc_lv_color.obj lvgl_src_lv_misc_lv_fs.obj lvgl_src_lv_misc_lv_gc.obj lvgl_src_lv_misc_lv_ll.obj lvgl_src_lv_misc_lv_log.obj lvgl_src_lv_misc_lv_math.obj lvgl_src_lv_misc_lv_mem.obj lvgl_src_lv_misc_lv_task.obj lvgl_src_lv_misc_lv_templ.obj lvgl_src_lv_misc_lv_txt.obj lvgl_src_lv_misc_lv_utils.obj lvgl_src_lv_objx_lv_arc.obj lvgl_src_lv_objx_lv_bar.obj lvgl_src_lv_objx_lv_btn.obj lvgl_src_lv_objx_lv_btnm.obj lvgl_src_lv_objx_lv_calendar.obj lvgl_src_lv_objx_lv_canvas.obj lvgl_src_lv_objx_lv_cb.obj lvgl_src_lv_objx_lv_chart.obj lvgl_src_lv_objx_lv_cont.obj lvgl_src_lv_objx_lv_ddlist.obj lvgl_src_lv_objx_lv_gauge.obj lvgl_src_lv_objx_lv_img.obj lvgl_src_lv_objx_lv_imgbtn.obj lvgl_src_lv_objx_lv_kb.obj lvgl_src_lv_objx_lv_label.obj lvgl_src_lv_objx_lv_led.obj lvgl_src_lv_objx_lv_line.obj lvgl_src_lv_objx_lv_list.obj lvgl_src_lv_objx_lv_lmeter.obj lvgl_src_lv_objx_lv_mbox.obj lvgl_src_lv_objx_lv_objx_templ.obj lvgl_src_lv_objx_lv_page.obj lvgl_src_lv_objx_lv_preload.obj lvgl_src_lv_objx_lv_roller.obj lvgl_src_lv_objx_lv_slider.obj lvgl_src_lv_objx_lv_spinbox.obj lvgl_src_lv_objx_lv_sw.obj lvgl_src_lv_objx_lv_ta.obj lvgl_src_lv_objx_lv_table.obj lvgl_src_lv_objx_lv_tabview.obj lvgl_src_lv_objx_lv_tileview.obj lvgl_src_lv_objx_lv_win.obj lvgl_src_lv_themes_lv_theme.obj lvgl_src_lv_themes_lv_theme_alien.obj lvgl_src_lv_themes_lv_theme_default.obj lvgl_src_lv_themes_lv_theme_material.obj lvgl_src_lv_themes_lv_theme_mono.obj lvgl_src_lv_themes_lv_theme_nemo.obj lvgl_src_lv_themes_lv_theme_night.obj lvgl_src_lv_themes_lv_theme_templ.obj lvgl_src_lv_themes_lv_theme_zen.obj

CONFIGPKG = $(KERNEL_BUILD)/ccs

NAME = kentectouchwidgets

CFLAGS = -I../.. \
    -I. \
    "-I$(SIMPLELINK_MSP432_SDK_INSTALL_DIR)/source" \
    "-I$(SIMPLELINK_MSP432_SDK_INSTALL_DIR)/source/third_party/CMSIS/Include" \
    --advice:power=none \
    -DLV_CONF_INCLUDE_SIMPLE \
    "-I$(SIMPLELINK_SDK_LVGL_PLUGIN_INSTALL_DIR)/source" \
    "-I$(SIMPLELINK_SDK_LVGL_PLUGIN_INSTALL_DIR)/source/third_party" \
    "-I$(SIMPLELINK_SDK_LVGL_PLUGIN_INSTALL_DIR)/source/third_party/lvgl" \
    "-I$(SIMPLELINK_MSP432_SDK_INSTALL_DIR)/source/ti/posix/ccs" \
    --silicon_version=7M4 \
    --code_state=16 \
    --little_endian \
    --display_error_number \
    --diag_warning=255 \
    --diag_wrap=off \
    --gen_func_subsections=on \
    --float_support=FPv4SPD16 \
    --symdebug:dwarf \
    "-I$(CCS_ARMCOMPILER)/include"

LFLAGS = "-i$(SIMPLELINK_MSP432_SDK_INSTALL_DIR)/source" \
    -lti/display/lib/display.aem4f \
    -lti/grlib/lib/ccs/m4f/grlib.a \
    -lthird_party/spiffs/lib/ccs/m4f/spiffs.a \
    -lti/drivers/lib/drivers_msp432p4x1xi.aem4f \
    -lthird_party/fatfs/lib/ccs/m4f/fatfs.a \
    "-i$(SIMPLELINK_MSP432_SDK_INSTALL_DIR)/kernel/tirtos/packages" \
    -lti/dpl/lib/dpl_msp432p4x1xi.aem4f \
    "-l$(KERNEL_BUILD)/ccs/linker.cmd" \
    -lti/devices/msp432p4xx/driverlib/ccs/msp432p4xx_driverlib.lib \
    ../../tirtos/ccs/MSP_EXP432P4111_TIRTOS.cmd \
    "-m$(NAME).map" \
    --warn_sections \
    --display_error_number \
    --diag_wrap=off \
    --rom_model \
    "-i$(CCS_ARMCOMPILER)/lib" \
    -llibc.a

all: $(NAME).out

$(CONFIGPKG)/linker.cmd $(CONFIGPKG)/compiler.opt:
	@ $(ECHOBLANKLINE)
	@ echo $(CONFIGPKG) is not built.
	@ echo You can build it by issuing $(MAKE) in $(CONFIGPKG).
	@ $(ECHOBLANKLINE)

.INTERMEDIATE: syscfg
Board.c ti_lvgl_ssd2119_disp.c lv_port_indev.c ti_lvgl_disp_interface.c Board.h lv_conf.h lv_drv_conf.h lv_port_disp.h lv_port_indev.h ti_lvgl_disp_interface.h: syscfg
	@ echo generation complete

syscfg: ../../kentectouchwidgets.syscfg
	@ echo Generating configuration files...
	@ $(SYSCONFIG_TOOL) --product $(SIMPLELINK_SDK_LVGL_PLUGIN_INSTALL_DIR)/.metadata/product.json --product $(SIMPLELINK_MSP432_SDK_INSTALL_DIR)/.metadata/product.json --output $(@D) $<

kentectouchwidgets.obj: ../../kentectouchwidgets.c Board.h lv_conf.h lv_drv_conf.h lv_port_disp.h lv_port_indev.h ti_lvgl_disp_interface.h $(CONFIGPKG)/compiler.opt
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< --cmd_file=$(CONFIGPKG)/compiler.opt --output_file=$@

tirtos_main_tirtos.obj: ../../tirtos/main_tirtos.c Board.h lv_conf.h lv_drv_conf.h lv_port_disp.h lv_port_indev.h ti_lvgl_disp_interface.h $(CONFIGPKG)/compiler.opt
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< --cmd_file=$(CONFIGPKG)/compiler.opt --output_file=$@

lvgl_src_lv_core_lv_disp.obj: $(SIMPLELINK_SDK_LVGL_PLUGIN_INSTALL_DIR)/source/third_party/lvgl/src/lv_core/lv_disp.c Board.h lv_conf.h lv_drv_conf.h lv_port_disp.h lv_port_indev.h ti_lvgl_disp_interface.h $(CONFIGPKG)/compiler.opt
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< --cmd_file=$(CONFIGPKG)/compiler.opt --output_file=$@

lvgl_src_lv_core_lv_group.obj: $(SIMPLELINK_SDK_LVGL_PLUGIN_INSTALL_DIR)/source/third_party/lvgl/src/lv_core/lv_group.c Board.h lv_conf.h lv_drv_conf.h lv_port_disp.h lv_port_indev.h ti_lvgl_disp_interface.h $(CONFIGPKG)/compiler.opt
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< --cmd_file=$(CONFIGPKG)/compiler.opt --output_file=$@

lvgl_src_lv_core_lv_indev.obj: $(SIMPLELINK_SDK_LVGL_PLUGIN_INSTALL_DIR)/source/third_party/lvgl/src/lv_core/lv_indev.c Board.h lv_conf.h lv_drv_conf.h lv_port_disp.h lv_port_indev.h ti_lvgl_disp_interface.h $(CONFIGPKG)/compiler.opt
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< --cmd_file=$(CONFIGPKG)/compiler.opt --output_file=$@

lvgl_src_lv_core_lv_obj.obj: $(SIMPLELINK_SDK_LVGL_PLUGIN_INSTALL_DIR)/source/third_party/lvgl/src/lv_core/lv_obj.c Board.h lv_conf.h lv_drv_conf.h lv_port_disp.h lv_port_indev.h ti_lvgl_disp_interface.h $(CONFIGPKG)/compiler.opt
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< --cmd_file=$(CONFIGPKG)/compiler.opt --output_file=$@

lvgl_src_lv_core_lv_refr.obj: $(SIMPLELINK_SDK_LVGL_PLUGIN_INSTALL_DIR)/source/third_party/lvgl/src/lv_core/lv_refr.c Board.h lv_conf.h lv_drv_conf.h lv_port_disp.h lv_port_indev.h ti_lvgl_disp_interface.h $(CONFIGPKG)/compiler.opt
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< --cmd_file=$(CONFIGPKG)/compiler.opt --output_file=$@

lvgl_src_lv_core_lv_style.obj: $(SIMPLELINK_SDK_LVGL_PLUGIN_INSTALL_DIR)/source/third_party/lvgl/src/lv_core/lv_style.c Board.h lv_conf.h lv_drv_conf.h lv_port_disp.h lv_port_indev.h ti_lvgl_disp_interface.h $(CONFIGPKG)/compiler.opt
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< --cmd_file=$(CONFIGPKG)/compiler.opt --output_file=$@

lvgl_src_lv_draw_lv_draw.obj: $(SIMPLELINK_SDK_LVGL_PLUGIN_INSTALL_DIR)/source/third_party/lvgl/src/lv_draw/lv_draw.c Board.h lv_conf.h lv_drv_conf.h lv_port_disp.h lv_port_indev.h ti_lvgl_disp_interface.h $(CONFIGPKG)/compiler.opt
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< --cmd_file=$(CONFIGPKG)/compiler.opt --output_file=$@

lvgl_src_lv_draw_lv_draw_arc.obj: $(SIMPLELINK_SDK_LVGL_PLUGIN_INSTALL_DIR)/source/third_party/lvgl/src/lv_draw/lv_draw_arc.c Board.h lv_conf.h lv_drv_conf.h lv_port_disp.h lv_port_indev.h ti_lvgl_disp_interface.h $(CONFIGPKG)/compiler.opt
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< --cmd_file=$(CONFIGPKG)/compiler.opt --output_file=$@

lvgl_src_lv_draw_lv_draw_basic.obj: $(SIMPLELINK_SDK_LVGL_PLUGIN_INSTALL_DIR)/source/third_party/lvgl/src/lv_draw/lv_draw_basic.c Board.h lv_conf.h lv_drv_conf.h lv_port_disp.h lv_port_indev.h ti_lvgl_disp_interface.h $(CONFIGPKG)/compiler.opt
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< --cmd_file=$(CONFIGPKG)/compiler.opt --output_file=$@

lvgl_src_lv_draw_lv_draw_img.obj: $(SIMPLELINK_SDK_LVGL_PLUGIN_INSTALL_DIR)/source/third_party/lvgl/src/lv_draw/lv_draw_img.c Board.h lv_conf.h lv_drv_conf.h lv_port_disp.h lv_port_indev.h ti_lvgl_disp_interface.h $(CONFIGPKG)/compiler.opt
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< --cmd_file=$(CONFIGPKG)/compiler.opt --output_file=$@

lvgl_src_lv_draw_lv_draw_label.obj: $(SIMPLELINK_SDK_LVGL_PLUGIN_INSTALL_DIR)/source/third_party/lvgl/src/lv_draw/lv_draw_label.c Board.h lv_conf.h lv_drv_conf.h lv_port_disp.h lv_port_indev.h ti_lvgl_disp_interface.h $(CONFIGPKG)/compiler.opt
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< --cmd_file=$(CONFIGPKG)/compiler.opt --output_file=$@

lvgl_src_lv_draw_lv_draw_line.obj: $(SIMPLELINK_SDK_LVGL_PLUGIN_INSTALL_DIR)/source/third_party/lvgl/src/lv_draw/lv_draw_line.c Board.h lv_conf.h lv_drv_conf.h lv_port_disp.h lv_port_indev.h ti_lvgl_disp_interface.h $(CONFIGPKG)/compiler.opt
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< --cmd_file=$(CONFIGPKG)/compiler.opt --output_file=$@

lvgl_src_lv_draw_lv_draw_rect.obj: $(SIMPLELINK_SDK_LVGL_PLUGIN_INSTALL_DIR)/source/third_party/lvgl/src/lv_draw/lv_draw_rect.c Board.h lv_conf.h lv_drv_conf.h lv_port_disp.h lv_port_indev.h ti_lvgl_disp_interface.h $(CONFIGPKG)/compiler.opt
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< --cmd_file=$(CONFIGPKG)/compiler.opt --output_file=$@

lvgl_src_lv_draw_lv_draw_triangle.obj: $(SIMPLELINK_SDK_LVGL_PLUGIN_INSTALL_DIR)/source/third_party/lvgl/src/lv_draw/lv_draw_triangle.c Board.h lv_conf.h lv_drv_conf.h lv_port_disp.h lv_port_indev.h ti_lvgl_disp_interface.h $(CONFIGPKG)/compiler.opt
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< --cmd_file=$(CONFIGPKG)/compiler.opt --output_file=$@

lvgl_src_lv_draw_lv_img_cache.obj: $(SIMPLELINK_SDK_LVGL_PLUGIN_INSTALL_DIR)/source/third_party/lvgl/src/lv_draw/lv_img_cache.c Board.h lv_conf.h lv_drv_conf.h lv_port_disp.h lv_port_indev.h ti_lvgl_disp_interface.h $(CONFIGPKG)/compiler.opt
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< --cmd_file=$(CONFIGPKG)/compiler.opt --output_file=$@

lvgl_src_lv_draw_lv_img_decoder.obj: $(SIMPLELINK_SDK_LVGL_PLUGIN_INSTALL_DIR)/source/third_party/lvgl/src/lv_draw/lv_img_decoder.c Board.h lv_conf.h lv_drv_conf.h lv_port_disp.h lv_port_indev.h ti_lvgl_disp_interface.h $(CONFIGPKG)/compiler.opt
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< --cmd_file=$(CONFIGPKG)/compiler.opt --output_file=$@

lvgl_src_lv_font_lv_font.obj: $(SIMPLELINK_SDK_LVGL_PLUGIN_INSTALL_DIR)/source/third_party/lvgl/src/lv_font/lv_font.c Board.h lv_conf.h lv_drv_conf.h lv_port_disp.h lv_port_indev.h ti_lvgl_disp_interface.h $(CONFIGPKG)/compiler.opt
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< --cmd_file=$(CONFIGPKG)/compiler.opt --output_file=$@

lvgl_src_lv_font_lv_font_fmt_txt.obj: $(SIMPLELINK_SDK_LVGL_PLUGIN_INSTALL_DIR)/source/third_party/lvgl/src/lv_font/lv_font_fmt_txt.c Board.h lv_conf.h lv_drv_conf.h lv_port_disp.h lv_port_indev.h ti_lvgl_disp_interface.h $(CONFIGPKG)/compiler.opt
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< --cmd_file=$(CONFIGPKG)/compiler.opt --output_file=$@

lvgl_src_lv_font_lv_font_roboto_12.obj: $(SIMPLELINK_SDK_LVGL_PLUGIN_INSTALL_DIR)/source/third_party/lvgl/src/lv_font/lv_font_roboto_12.c Board.h lv_conf.h lv_drv_conf.h lv_port_disp.h lv_port_indev.h ti_lvgl_disp_interface.h $(CONFIGPKG)/compiler.opt
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< --cmd_file=$(CONFIGPKG)/compiler.opt --output_file=$@

lvgl_src_lv_font_lv_font_roboto_16.obj: $(SIMPLELINK_SDK_LVGL_PLUGIN_INSTALL_DIR)/source/third_party/lvgl/src/lv_font/lv_font_roboto_16.c Board.h lv_conf.h lv_drv_conf.h lv_port_disp.h lv_port_indev.h ti_lvgl_disp_interface.h $(CONFIGPKG)/compiler.opt
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< --cmd_file=$(CONFIGPKG)/compiler.opt --output_file=$@

lvgl_src_lv_font_lv_font_roboto_22.obj: $(SIMPLELINK_SDK_LVGL_PLUGIN_INSTALL_DIR)/source/third_party/lvgl/src/lv_font/lv_font_roboto_22.c Board.h lv_conf.h lv_drv_conf.h lv_port_disp.h lv_port_indev.h ti_lvgl_disp_interface.h $(CONFIGPKG)/compiler.opt
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< --cmd_file=$(CONFIGPKG)/compiler.opt --output_file=$@

lvgl_src_lv_font_lv_font_roboto_28.obj: $(SIMPLELINK_SDK_LVGL_PLUGIN_INSTALL_DIR)/source/third_party/lvgl/src/lv_font/lv_font_roboto_28.c Board.h lv_conf.h lv_drv_conf.h lv_port_disp.h lv_port_indev.h ti_lvgl_disp_interface.h $(CONFIGPKG)/compiler.opt
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< --cmd_file=$(CONFIGPKG)/compiler.opt --output_file=$@

lvgl_src_lv_font_lv_font_unscii_8.obj: $(SIMPLELINK_SDK_LVGL_PLUGIN_INSTALL_DIR)/source/third_party/lvgl/src/lv_font/lv_font_unscii_8.c Board.h lv_conf.h lv_drv_conf.h lv_port_disp.h lv_port_indev.h ti_lvgl_disp_interface.h $(CONFIGPKG)/compiler.opt
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< --cmd_file=$(CONFIGPKG)/compiler.opt --output_file=$@

lvgl_src_lv_hal_lv_hal_disp.obj: $(SIMPLELINK_SDK_LVGL_PLUGIN_INSTALL_DIR)/source/third_party/lvgl/src/lv_hal/lv_hal_disp.c Board.h lv_conf.h lv_drv_conf.h lv_port_disp.h lv_port_indev.h ti_lvgl_disp_interface.h $(CONFIGPKG)/compiler.opt
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< --cmd_file=$(CONFIGPKG)/compiler.opt --output_file=$@

lvgl_src_lv_hal_lv_hal_indev.obj: $(SIMPLELINK_SDK_LVGL_PLUGIN_INSTALL_DIR)/source/third_party/lvgl/src/lv_hal/lv_hal_indev.c Board.h lv_conf.h lv_drv_conf.h lv_port_disp.h lv_port_indev.h ti_lvgl_disp_interface.h $(CONFIGPKG)/compiler.opt
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< --cmd_file=$(CONFIGPKG)/compiler.opt --output_file=$@

lvgl_src_lv_hal_lv_hal_tick.obj: $(SIMPLELINK_SDK_LVGL_PLUGIN_INSTALL_DIR)/source/third_party/lvgl/src/lv_hal/lv_hal_tick.c Board.h lv_conf.h lv_drv_conf.h lv_port_disp.h lv_port_indev.h ti_lvgl_disp_interface.h $(CONFIGPKG)/compiler.opt
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< --cmd_file=$(CONFIGPKG)/compiler.opt --output_file=$@

lvgl_src_lv_misc_lv_anim.obj: $(SIMPLELINK_SDK_LVGL_PLUGIN_INSTALL_DIR)/source/third_party/lvgl/src/lv_misc/lv_anim.c Board.h lv_conf.h lv_drv_conf.h lv_port_disp.h lv_port_indev.h ti_lvgl_disp_interface.h $(CONFIGPKG)/compiler.opt
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< --cmd_file=$(CONFIGPKG)/compiler.opt --output_file=$@

lvgl_src_lv_misc_lv_area.obj: $(SIMPLELINK_SDK_LVGL_PLUGIN_INSTALL_DIR)/source/third_party/lvgl/src/lv_misc/lv_area.c Board.h lv_conf.h lv_drv_conf.h lv_port_disp.h lv_port_indev.h ti_lvgl_disp_interface.h $(CONFIGPKG)/compiler.opt
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< --cmd_file=$(CONFIGPKG)/compiler.opt --output_file=$@

lvgl_src_lv_misc_lv_async.obj: $(SIMPLELINK_SDK_LVGL_PLUGIN_INSTALL_DIR)/source/third_party/lvgl/src/lv_misc/lv_async.c Board.h lv_conf.h lv_drv_conf.h lv_port_disp.h lv_port_indev.h ti_lvgl_disp_interface.h $(CONFIGPKG)/compiler.opt
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< --cmd_file=$(CONFIGPKG)/compiler.opt --output_file=$@

lvgl_src_lv_misc_lv_circ.obj: $(SIMPLELINK_SDK_LVGL_PLUGIN_INSTALL_DIR)/source/third_party/lvgl/src/lv_misc/lv_circ.c Board.h lv_conf.h lv_drv_conf.h lv_port_disp.h lv_port_indev.h ti_lvgl_disp_interface.h $(CONFIGPKG)/compiler.opt
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< --cmd_file=$(CONFIGPKG)/compiler.opt --output_file=$@

lvgl_src_lv_misc_lv_color.obj: $(SIMPLELINK_SDK_LVGL_PLUGIN_INSTALL_DIR)/source/third_party/lvgl/src/lv_misc/lv_color.c Board.h lv_conf.h lv_drv_conf.h lv_port_disp.h lv_port_indev.h ti_lvgl_disp_interface.h $(CONFIGPKG)/compiler.opt
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< --cmd_file=$(CONFIGPKG)/compiler.opt --output_file=$@

lvgl_src_lv_misc_lv_fs.obj: $(SIMPLELINK_SDK_LVGL_PLUGIN_INSTALL_DIR)/source/third_party/lvgl/src/lv_misc/lv_fs.c Board.h lv_conf.h lv_drv_conf.h lv_port_disp.h lv_port_indev.h ti_lvgl_disp_interface.h $(CONFIGPKG)/compiler.opt
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< --cmd_file=$(CONFIGPKG)/compiler.opt --output_file=$@

lvgl_src_lv_misc_lv_gc.obj: $(SIMPLELINK_SDK_LVGL_PLUGIN_INSTALL_DIR)/source/third_party/lvgl/src/lv_misc/lv_gc.c Board.h lv_conf.h lv_drv_conf.h lv_port_disp.h lv_port_indev.h ti_lvgl_disp_interface.h $(CONFIGPKG)/compiler.opt
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< --cmd_file=$(CONFIGPKG)/compiler.opt --output_file=$@

lvgl_src_lv_misc_lv_ll.obj: $(SIMPLELINK_SDK_LVGL_PLUGIN_INSTALL_DIR)/source/third_party/lvgl/src/lv_misc/lv_ll.c Board.h lv_conf.h lv_drv_conf.h lv_port_disp.h lv_port_indev.h ti_lvgl_disp_interface.h $(CONFIGPKG)/compiler.opt
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< --cmd_file=$(CONFIGPKG)/compiler.opt --output_file=$@

lvgl_src_lv_misc_lv_log.obj: $(SIMPLELINK_SDK_LVGL_PLUGIN_INSTALL_DIR)/source/third_party/lvgl/src/lv_misc/lv_log.c Board.h lv_conf.h lv_drv_conf.h lv_port_disp.h lv_port_indev.h ti_lvgl_disp_interface.h $(CONFIGPKG)/compiler.opt
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< --cmd_file=$(CONFIGPKG)/compiler.opt --output_file=$@

lvgl_src_lv_misc_lv_math.obj: $(SIMPLELINK_SDK_LVGL_PLUGIN_INSTALL_DIR)/source/third_party/lvgl/src/lv_misc/lv_math.c Board.h lv_conf.h lv_drv_conf.h lv_port_disp.h lv_port_indev.h ti_lvgl_disp_interface.h $(CONFIGPKG)/compiler.opt
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< --cmd_file=$(CONFIGPKG)/compiler.opt --output_file=$@

lvgl_src_lv_misc_lv_mem.obj: $(SIMPLELINK_SDK_LVGL_PLUGIN_INSTALL_DIR)/source/third_party/lvgl/src/lv_misc/lv_mem.c Board.h lv_conf.h lv_drv_conf.h lv_port_disp.h lv_port_indev.h ti_lvgl_disp_interface.h $(CONFIGPKG)/compiler.opt
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< --cmd_file=$(CONFIGPKG)/compiler.opt --output_file=$@

lvgl_src_lv_misc_lv_task.obj: $(SIMPLELINK_SDK_LVGL_PLUGIN_INSTALL_DIR)/source/third_party/lvgl/src/lv_misc/lv_task.c Board.h lv_conf.h lv_drv_conf.h lv_port_disp.h lv_port_indev.h ti_lvgl_disp_interface.h $(CONFIGPKG)/compiler.opt
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< --cmd_file=$(CONFIGPKG)/compiler.opt --output_file=$@

lvgl_src_lv_misc_lv_templ.obj: $(SIMPLELINK_SDK_LVGL_PLUGIN_INSTALL_DIR)/source/third_party/lvgl/src/lv_misc/lv_templ.c Board.h lv_conf.h lv_drv_conf.h lv_port_disp.h lv_port_indev.h ti_lvgl_disp_interface.h $(CONFIGPKG)/compiler.opt
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< --cmd_file=$(CONFIGPKG)/compiler.opt --output_file=$@

lvgl_src_lv_misc_lv_txt.obj: $(SIMPLELINK_SDK_LVGL_PLUGIN_INSTALL_DIR)/source/third_party/lvgl/src/lv_misc/lv_txt.c Board.h lv_conf.h lv_drv_conf.h lv_port_disp.h lv_port_indev.h ti_lvgl_disp_interface.h $(CONFIGPKG)/compiler.opt
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< --cmd_file=$(CONFIGPKG)/compiler.opt --output_file=$@

lvgl_src_lv_misc_lv_utils.obj: $(SIMPLELINK_SDK_LVGL_PLUGIN_INSTALL_DIR)/source/third_party/lvgl/src/lv_misc/lv_utils.c Board.h lv_conf.h lv_drv_conf.h lv_port_disp.h lv_port_indev.h ti_lvgl_disp_interface.h $(CONFIGPKG)/compiler.opt
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< --cmd_file=$(CONFIGPKG)/compiler.opt --output_file=$@

lvgl_src_lv_objx_lv_arc.obj: $(SIMPLELINK_SDK_LVGL_PLUGIN_INSTALL_DIR)/source/third_party/lvgl/src/lv_objx/lv_arc.c Board.h lv_conf.h lv_drv_conf.h lv_port_disp.h lv_port_indev.h ti_lvgl_disp_interface.h $(CONFIGPKG)/compiler.opt
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< --cmd_file=$(CONFIGPKG)/compiler.opt --output_file=$@

lvgl_src_lv_objx_lv_bar.obj: $(SIMPLELINK_SDK_LVGL_PLUGIN_INSTALL_DIR)/source/third_party/lvgl/src/lv_objx/lv_bar.c Board.h lv_conf.h lv_drv_conf.h lv_port_disp.h lv_port_indev.h ti_lvgl_disp_interface.h $(CONFIGPKG)/compiler.opt
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< --cmd_file=$(CONFIGPKG)/compiler.opt --output_file=$@

lvgl_src_lv_objx_lv_btn.obj: $(SIMPLELINK_SDK_LVGL_PLUGIN_INSTALL_DIR)/source/third_party/lvgl/src/lv_objx/lv_btn.c Board.h lv_conf.h lv_drv_conf.h lv_port_disp.h lv_port_indev.h ti_lvgl_disp_interface.h $(CONFIGPKG)/compiler.opt
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< --cmd_file=$(CONFIGPKG)/compiler.opt --output_file=$@

lvgl_src_lv_objx_lv_btnm.obj: $(SIMPLELINK_SDK_LVGL_PLUGIN_INSTALL_DIR)/source/third_party/lvgl/src/lv_objx/lv_btnm.c Board.h lv_conf.h lv_drv_conf.h lv_port_disp.h lv_port_indev.h ti_lvgl_disp_interface.h $(CONFIGPKG)/compiler.opt
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< --cmd_file=$(CONFIGPKG)/compiler.opt --output_file=$@

lvgl_src_lv_objx_lv_calendar.obj: $(SIMPLELINK_SDK_LVGL_PLUGIN_INSTALL_DIR)/source/third_party/lvgl/src/lv_objx/lv_calendar.c Board.h lv_conf.h lv_drv_conf.h lv_port_disp.h lv_port_indev.h ti_lvgl_disp_interface.h $(CONFIGPKG)/compiler.opt
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< --cmd_file=$(CONFIGPKG)/compiler.opt --output_file=$@

lvgl_src_lv_objx_lv_canvas.obj: $(SIMPLELINK_SDK_LVGL_PLUGIN_INSTALL_DIR)/source/third_party/lvgl/src/lv_objx/lv_canvas.c Board.h lv_conf.h lv_drv_conf.h lv_port_disp.h lv_port_indev.h ti_lvgl_disp_interface.h $(CONFIGPKG)/compiler.opt
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< --cmd_file=$(CONFIGPKG)/compiler.opt --output_file=$@

lvgl_src_lv_objx_lv_cb.obj: $(SIMPLELINK_SDK_LVGL_PLUGIN_INSTALL_DIR)/source/third_party/lvgl/src/lv_objx/lv_cb.c Board.h lv_conf.h lv_drv_conf.h lv_port_disp.h lv_port_indev.h ti_lvgl_disp_interface.h $(CONFIGPKG)/compiler.opt
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< --cmd_file=$(CONFIGPKG)/compiler.opt --output_file=$@

lvgl_src_lv_objx_lv_chart.obj: $(SIMPLELINK_SDK_LVGL_PLUGIN_INSTALL_DIR)/source/third_party/lvgl/src/lv_objx/lv_chart.c Board.h lv_conf.h lv_drv_conf.h lv_port_disp.h lv_port_indev.h ti_lvgl_disp_interface.h $(CONFIGPKG)/compiler.opt
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< --cmd_file=$(CONFIGPKG)/compiler.opt --output_file=$@

lvgl_src_lv_objx_lv_cont.obj: $(SIMPLELINK_SDK_LVGL_PLUGIN_INSTALL_DIR)/source/third_party/lvgl/src/lv_objx/lv_cont.c Board.h lv_conf.h lv_drv_conf.h lv_port_disp.h lv_port_indev.h ti_lvgl_disp_interface.h $(CONFIGPKG)/compiler.opt
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< --cmd_file=$(CONFIGPKG)/compiler.opt --output_file=$@

lvgl_src_lv_objx_lv_ddlist.obj: $(SIMPLELINK_SDK_LVGL_PLUGIN_INSTALL_DIR)/source/third_party/lvgl/src/lv_objx/lv_ddlist.c Board.h lv_conf.h lv_drv_conf.h lv_port_disp.h lv_port_indev.h ti_lvgl_disp_interface.h $(CONFIGPKG)/compiler.opt
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< --cmd_file=$(CONFIGPKG)/compiler.opt --output_file=$@

lvgl_src_lv_objx_lv_gauge.obj: $(SIMPLELINK_SDK_LVGL_PLUGIN_INSTALL_DIR)/source/third_party/lvgl/src/lv_objx/lv_gauge.c Board.h lv_conf.h lv_drv_conf.h lv_port_disp.h lv_port_indev.h ti_lvgl_disp_interface.h $(CONFIGPKG)/compiler.opt
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< --cmd_file=$(CONFIGPKG)/compiler.opt --output_file=$@

lvgl_src_lv_objx_lv_img.obj: $(SIMPLELINK_SDK_LVGL_PLUGIN_INSTALL_DIR)/source/third_party/lvgl/src/lv_objx/lv_img.c Board.h lv_conf.h lv_drv_conf.h lv_port_disp.h lv_port_indev.h ti_lvgl_disp_interface.h $(CONFIGPKG)/compiler.opt
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< --cmd_file=$(CONFIGPKG)/compiler.opt --output_file=$@

lvgl_src_lv_objx_lv_imgbtn.obj: $(SIMPLELINK_SDK_LVGL_PLUGIN_INSTALL_DIR)/source/third_party/lvgl/src/lv_objx/lv_imgbtn.c Board.h lv_conf.h lv_drv_conf.h lv_port_disp.h lv_port_indev.h ti_lvgl_disp_interface.h $(CONFIGPKG)/compiler.opt
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< --cmd_file=$(CONFIGPKG)/compiler.opt --output_file=$@

lvgl_src_lv_objx_lv_kb.obj: $(SIMPLELINK_SDK_LVGL_PLUGIN_INSTALL_DIR)/source/third_party/lvgl/src/lv_objx/lv_kb.c Board.h lv_conf.h lv_drv_conf.h lv_port_disp.h lv_port_indev.h ti_lvgl_disp_interface.h $(CONFIGPKG)/compiler.opt
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< --cmd_file=$(CONFIGPKG)/compiler.opt --output_file=$@

lvgl_src_lv_objx_lv_label.obj: $(SIMPLELINK_SDK_LVGL_PLUGIN_INSTALL_DIR)/source/third_party/lvgl/src/lv_objx/lv_label.c Board.h lv_conf.h lv_drv_conf.h lv_port_disp.h lv_port_indev.h ti_lvgl_disp_interface.h $(CONFIGPKG)/compiler.opt
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< --cmd_file=$(CONFIGPKG)/compiler.opt --output_file=$@

lvgl_src_lv_objx_lv_led.obj: $(SIMPLELINK_SDK_LVGL_PLUGIN_INSTALL_DIR)/source/third_party/lvgl/src/lv_objx/lv_led.c Board.h lv_conf.h lv_drv_conf.h lv_port_disp.h lv_port_indev.h ti_lvgl_disp_interface.h $(CONFIGPKG)/compiler.opt
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< --cmd_file=$(CONFIGPKG)/compiler.opt --output_file=$@

lvgl_src_lv_objx_lv_line.obj: $(SIMPLELINK_SDK_LVGL_PLUGIN_INSTALL_DIR)/source/third_party/lvgl/src/lv_objx/lv_line.c Board.h lv_conf.h lv_drv_conf.h lv_port_disp.h lv_port_indev.h ti_lvgl_disp_interface.h $(CONFIGPKG)/compiler.opt
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< --cmd_file=$(CONFIGPKG)/compiler.opt --output_file=$@

lvgl_src_lv_objx_lv_list.obj: $(SIMPLELINK_SDK_LVGL_PLUGIN_INSTALL_DIR)/source/third_party/lvgl/src/lv_objx/lv_list.c Board.h lv_conf.h lv_drv_conf.h lv_port_disp.h lv_port_indev.h ti_lvgl_disp_interface.h $(CONFIGPKG)/compiler.opt
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< --cmd_file=$(CONFIGPKG)/compiler.opt --output_file=$@

lvgl_src_lv_objx_lv_lmeter.obj: $(SIMPLELINK_SDK_LVGL_PLUGIN_INSTALL_DIR)/source/third_party/lvgl/src/lv_objx/lv_lmeter.c Board.h lv_conf.h lv_drv_conf.h lv_port_disp.h lv_port_indev.h ti_lvgl_disp_interface.h $(CONFIGPKG)/compiler.opt
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< --cmd_file=$(CONFIGPKG)/compiler.opt --output_file=$@

lvgl_src_lv_objx_lv_mbox.obj: $(SIMPLELINK_SDK_LVGL_PLUGIN_INSTALL_DIR)/source/third_party/lvgl/src/lv_objx/lv_mbox.c Board.h lv_conf.h lv_drv_conf.h lv_port_disp.h lv_port_indev.h ti_lvgl_disp_interface.h $(CONFIGPKG)/compiler.opt
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< --cmd_file=$(CONFIGPKG)/compiler.opt --output_file=$@

lvgl_src_lv_objx_lv_objx_templ.obj: $(SIMPLELINK_SDK_LVGL_PLUGIN_INSTALL_DIR)/source/third_party/lvgl/src/lv_objx/lv_objx_templ.c Board.h lv_conf.h lv_drv_conf.h lv_port_disp.h lv_port_indev.h ti_lvgl_disp_interface.h $(CONFIGPKG)/compiler.opt
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< --cmd_file=$(CONFIGPKG)/compiler.opt --output_file=$@

lvgl_src_lv_objx_lv_page.obj: $(SIMPLELINK_SDK_LVGL_PLUGIN_INSTALL_DIR)/source/third_party/lvgl/src/lv_objx/lv_page.c Board.h lv_conf.h lv_drv_conf.h lv_port_disp.h lv_port_indev.h ti_lvgl_disp_interface.h $(CONFIGPKG)/compiler.opt
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< --cmd_file=$(CONFIGPKG)/compiler.opt --output_file=$@

lvgl_src_lv_objx_lv_preload.obj: $(SIMPLELINK_SDK_LVGL_PLUGIN_INSTALL_DIR)/source/third_party/lvgl/src/lv_objx/lv_preload.c Board.h lv_conf.h lv_drv_conf.h lv_port_disp.h lv_port_indev.h ti_lvgl_disp_interface.h $(CONFIGPKG)/compiler.opt
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< --cmd_file=$(CONFIGPKG)/compiler.opt --output_file=$@

lvgl_src_lv_objx_lv_roller.obj: $(SIMPLELINK_SDK_LVGL_PLUGIN_INSTALL_DIR)/source/third_party/lvgl/src/lv_objx/lv_roller.c Board.h lv_conf.h lv_drv_conf.h lv_port_disp.h lv_port_indev.h ti_lvgl_disp_interface.h $(CONFIGPKG)/compiler.opt
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< --cmd_file=$(CONFIGPKG)/compiler.opt --output_file=$@

lvgl_src_lv_objx_lv_slider.obj: $(SIMPLELINK_SDK_LVGL_PLUGIN_INSTALL_DIR)/source/third_party/lvgl/src/lv_objx/lv_slider.c Board.h lv_conf.h lv_drv_conf.h lv_port_disp.h lv_port_indev.h ti_lvgl_disp_interface.h $(CONFIGPKG)/compiler.opt
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< --cmd_file=$(CONFIGPKG)/compiler.opt --output_file=$@

lvgl_src_lv_objx_lv_spinbox.obj: $(SIMPLELINK_SDK_LVGL_PLUGIN_INSTALL_DIR)/source/third_party/lvgl/src/lv_objx/lv_spinbox.c Board.h lv_conf.h lv_drv_conf.h lv_port_disp.h lv_port_indev.h ti_lvgl_disp_interface.h $(CONFIGPKG)/compiler.opt
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< --cmd_file=$(CONFIGPKG)/compiler.opt --output_file=$@

lvgl_src_lv_objx_lv_sw.obj: $(SIMPLELINK_SDK_LVGL_PLUGIN_INSTALL_DIR)/source/third_party/lvgl/src/lv_objx/lv_sw.c Board.h lv_conf.h lv_drv_conf.h lv_port_disp.h lv_port_indev.h ti_lvgl_disp_interface.h $(CONFIGPKG)/compiler.opt
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< --cmd_file=$(CONFIGPKG)/compiler.opt --output_file=$@

lvgl_src_lv_objx_lv_ta.obj: $(SIMPLELINK_SDK_LVGL_PLUGIN_INSTALL_DIR)/source/third_party/lvgl/src/lv_objx/lv_ta.c Board.h lv_conf.h lv_drv_conf.h lv_port_disp.h lv_port_indev.h ti_lvgl_disp_interface.h $(CONFIGPKG)/compiler.opt
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< --cmd_file=$(CONFIGPKG)/compiler.opt --output_file=$@

lvgl_src_lv_objx_lv_table.obj: $(SIMPLELINK_SDK_LVGL_PLUGIN_INSTALL_DIR)/source/third_party/lvgl/src/lv_objx/lv_table.c Board.h lv_conf.h lv_drv_conf.h lv_port_disp.h lv_port_indev.h ti_lvgl_disp_interface.h $(CONFIGPKG)/compiler.opt
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< --cmd_file=$(CONFIGPKG)/compiler.opt --output_file=$@

lvgl_src_lv_objx_lv_tabview.obj: $(SIMPLELINK_SDK_LVGL_PLUGIN_INSTALL_DIR)/source/third_party/lvgl/src/lv_objx/lv_tabview.c Board.h lv_conf.h lv_drv_conf.h lv_port_disp.h lv_port_indev.h ti_lvgl_disp_interface.h $(CONFIGPKG)/compiler.opt
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< --cmd_file=$(CONFIGPKG)/compiler.opt --output_file=$@

lvgl_src_lv_objx_lv_tileview.obj: $(SIMPLELINK_SDK_LVGL_PLUGIN_INSTALL_DIR)/source/third_party/lvgl/src/lv_objx/lv_tileview.c Board.h lv_conf.h lv_drv_conf.h lv_port_disp.h lv_port_indev.h ti_lvgl_disp_interface.h $(CONFIGPKG)/compiler.opt
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< --cmd_file=$(CONFIGPKG)/compiler.opt --output_file=$@

lvgl_src_lv_objx_lv_win.obj: $(SIMPLELINK_SDK_LVGL_PLUGIN_INSTALL_DIR)/source/third_party/lvgl/src/lv_objx/lv_win.c Board.h lv_conf.h lv_drv_conf.h lv_port_disp.h lv_port_indev.h ti_lvgl_disp_interface.h $(CONFIGPKG)/compiler.opt
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< --cmd_file=$(CONFIGPKG)/compiler.opt --output_file=$@

lvgl_src_lv_themes_lv_theme.obj: $(SIMPLELINK_SDK_LVGL_PLUGIN_INSTALL_DIR)/source/third_party/lvgl/src/lv_themes/lv_theme.c Board.h lv_conf.h lv_drv_conf.h lv_port_disp.h lv_port_indev.h ti_lvgl_disp_interface.h $(CONFIGPKG)/compiler.opt
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< --cmd_file=$(CONFIGPKG)/compiler.opt --output_file=$@

lvgl_src_lv_themes_lv_theme_alien.obj: $(SIMPLELINK_SDK_LVGL_PLUGIN_INSTALL_DIR)/source/third_party/lvgl/src/lv_themes/lv_theme_alien.c Board.h lv_conf.h lv_drv_conf.h lv_port_disp.h lv_port_indev.h ti_lvgl_disp_interface.h $(CONFIGPKG)/compiler.opt
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< --cmd_file=$(CONFIGPKG)/compiler.opt --output_file=$@

lvgl_src_lv_themes_lv_theme_default.obj: $(SIMPLELINK_SDK_LVGL_PLUGIN_INSTALL_DIR)/source/third_party/lvgl/src/lv_themes/lv_theme_default.c Board.h lv_conf.h lv_drv_conf.h lv_port_disp.h lv_port_indev.h ti_lvgl_disp_interface.h $(CONFIGPKG)/compiler.opt
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< --cmd_file=$(CONFIGPKG)/compiler.opt --output_file=$@

lvgl_src_lv_themes_lv_theme_material.obj: $(SIMPLELINK_SDK_LVGL_PLUGIN_INSTALL_DIR)/source/third_party/lvgl/src/lv_themes/lv_theme_material.c Board.h lv_conf.h lv_drv_conf.h lv_port_disp.h lv_port_indev.h ti_lvgl_disp_interface.h $(CONFIGPKG)/compiler.opt
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< --cmd_file=$(CONFIGPKG)/compiler.opt --output_file=$@

lvgl_src_lv_themes_lv_theme_mono.obj: $(SIMPLELINK_SDK_LVGL_PLUGIN_INSTALL_DIR)/source/third_party/lvgl/src/lv_themes/lv_theme_mono.c Board.h lv_conf.h lv_drv_conf.h lv_port_disp.h lv_port_indev.h ti_lvgl_disp_interface.h $(CONFIGPKG)/compiler.opt
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< --cmd_file=$(CONFIGPKG)/compiler.opt --output_file=$@

lvgl_src_lv_themes_lv_theme_nemo.obj: $(SIMPLELINK_SDK_LVGL_PLUGIN_INSTALL_DIR)/source/third_party/lvgl/src/lv_themes/lv_theme_nemo.c Board.h lv_conf.h lv_drv_conf.h lv_port_disp.h lv_port_indev.h ti_lvgl_disp_interface.h $(CONFIGPKG)/compiler.opt
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< --cmd_file=$(CONFIGPKG)/compiler.opt --output_file=$@

lvgl_src_lv_themes_lv_theme_night.obj: $(SIMPLELINK_SDK_LVGL_PLUGIN_INSTALL_DIR)/source/third_party/lvgl/src/lv_themes/lv_theme_night.c Board.h lv_conf.h lv_drv_conf.h lv_port_disp.h lv_port_indev.h ti_lvgl_disp_interface.h $(CONFIGPKG)/compiler.opt
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< --cmd_file=$(CONFIGPKG)/compiler.opt --output_file=$@

lvgl_src_lv_themes_lv_theme_templ.obj: $(SIMPLELINK_SDK_LVGL_PLUGIN_INSTALL_DIR)/source/third_party/lvgl/src/lv_themes/lv_theme_templ.c Board.h lv_conf.h lv_drv_conf.h lv_port_disp.h lv_port_indev.h ti_lvgl_disp_interface.h $(CONFIGPKG)/compiler.opt
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< --cmd_file=$(CONFIGPKG)/compiler.opt --output_file=$@

lvgl_src_lv_themes_lv_theme_zen.obj: $(SIMPLELINK_SDK_LVGL_PLUGIN_INSTALL_DIR)/source/third_party/lvgl/src/lv_themes/lv_theme_zen.c Board.h lv_conf.h lv_drv_conf.h lv_port_disp.h lv_port_indev.h ti_lvgl_disp_interface.h $(CONFIGPKG)/compiler.opt
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< --cmd_file=$(CONFIGPKG)/compiler.opt --output_file=$@

Board.obj: Board.c Board.h lv_conf.h lv_drv_conf.h lv_port_disp.h lv_port_indev.h ti_lvgl_disp_interface.h $(CONFIGPKG)/compiler.opt
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< --cmd_file=$(CONFIGPKG)/compiler.opt --output_file=$@

ti_lvgl_ssd2119_disp.obj: ti_lvgl_ssd2119_disp.c Board.h lv_conf.h lv_drv_conf.h lv_port_disp.h lv_port_indev.h ti_lvgl_disp_interface.h $(CONFIGPKG)/compiler.opt
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< --cmd_file=$(CONFIGPKG)/compiler.opt --output_file=$@

lv_port_indev.obj: lv_port_indev.c Board.h lv_conf.h lv_drv_conf.h lv_port_disp.h lv_port_indev.h ti_lvgl_disp_interface.h $(CONFIGPKG)/compiler.opt
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< --cmd_file=$(CONFIGPKG)/compiler.opt --output_file=$@

ti_lvgl_disp_interface.obj: ti_lvgl_disp_interface.c Board.h lv_conf.h lv_drv_conf.h lv_port_disp.h lv_port_indev.h ti_lvgl_disp_interface.h $(CONFIGPKG)/compiler.opt
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< --cmd_file=$(CONFIGPKG)/compiler.opt --output_file=$@

$(NAME).out: $(OBJECTS) $(CONFIGPKG)/linker.cmd
	@ echo linking $@
	@ $(LNK) -z $(OBJECTS)  $(LFLAGS) -o $(NAME).out

clean:
	@ echo Cleaning...
	@ $(RM) $(OBJECTS) > $(DEVNULL) 2>&1
	@ $(RM) $(NAME).out > $(DEVNULL) 2>&1
	@ $(RM) $(NAME).map > $(DEVNULL) 2>&1
	@ $(RM) Board.c ti_lvgl_ssd2119_disp.c lv_port_indev.c ti_lvgl_disp_interface.c Board.h lv_conf.h lv_drv_conf.h lv_port_disp.h lv_port_indev.h ti_lvgl_disp_interface.h > $(DEVNULL) 2>&1
