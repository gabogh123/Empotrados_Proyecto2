# -*- Makefile ; coding: utf-8 -*-

# © 2010 Intel Corporation

#
# See Simics Model Builder User's Guide for more details on what to put here.
#

MODULE_CLASSES = image_capturing_device
SRC_FILES = image_capturing_device.dml
PYTHON_FILES = module_load.py

SIMICS_API := 6
THREAD_SAFE := yes

ifeq ($(MODULE_MAKEFILE),)
$(error Make sure you compile your module from the project directory)
else
include $(MODULE_MAKEFILE)
endif
