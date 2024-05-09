#include <linux/module.h>
#define INCLUDE_VERMAGIC
#include <linux/build-salt.h>
#include <linux/elfnote-lto.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

BUILD_SALT;
BUILD_LTO_INFO;

MODULE_INFO(vermagic, VERMAGIC_STRING);
MODULE_INFO(name, KBUILD_MODNAME);

__visible struct module __this_module
__section(".gnu.linkonce.this_module") = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

#ifdef CONFIG_RETPOLINE
MODULE_INFO(retpoline, "Y");
#endif

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0xcd6bb128, "module_layout" },
	{ 0x6f029675, "kmalloc_caches" },
	{ 0xea471331, "cdev_init" },
	{ 0xf1f86b2f, "pci_disable_device" },
	{ 0xd21b20af, "device_destroy" },
	{ 0x9e5238bf, "pci_release_regions" },
	{ 0x6091b333, "unregister_chrdev_region" },
	{ 0x6b10bee1, "_copy_to_user" },
	{ 0x5b8239ca, "__x86_return_thunk" },
	{ 0x3d9f0c47, "class_unregister" },
	{ 0xde80cd09, "ioremap" },
	{ 0x7c800a1d, "pci_read_config_word" },
	{ 0x6d8c728f, "device_create" },
	{ 0xa357695, "cdev_add" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x92997ed8, "_printk" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x87be12d6, "pci_unregister_driver" },
	{ 0x3480d929, "kmem_cache_alloc_trace" },
	{ 0x37a0cba, "kfree" },
	{ 0x53a75729, "pci_request_regions" },
	{ 0xedc03953, "iounmap" },
	{ 0x3dd8f33b, "__pci_register_driver" },
	{ 0xb97ac27d, "class_destroy" },
	{ 0x4a453f53, "iowrite32" },
	{ 0xe8680a7a, "pci_enable_device" },
	{ 0x13c49cc2, "_copy_from_user" },
	{ 0xda8ecfb, "__class_create" },
	{ 0x88db9f48, "__check_object_size" },
	{ 0xe3ec2f2b, "alloc_chrdev_region" },
	{ 0xa78af5f3, "ioread32" },
	{ 0x9c6febfc, "add_uevent_var" },
};

MODULE_INFO(depends, "");

MODULE_ALIAS("pci:v0000104Cd0000AC10sv*sd*bc*sc*i*");

MODULE_INFO(srcversion, "3AA0F22585E6659390D81F0");
