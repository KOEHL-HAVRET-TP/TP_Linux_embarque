#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
//#include <sys/mman.h>

#define DRIVER_AUTHOR "Loïcia"
#define DRIVER_DESC "Hello world Module"
#define DRIVER_LICENSE "GPL"

static int param;

module_param(param, int, 0);
MODULE_PARM_DESC(param, "Un parametre de ce module");

int hello_init(void)
{
	printk(KERN_INFO "Hello world!\n");
	printk(KERN_DEBUG "le parametre est =%d\n", param);
	const char *name = "ensea"
	struct proc_dir_entry *proc_mkdir(*name, struct proc_dir_entry *parent);
	return 0;
}

void hello_exit(void)
{
	printk(KERN_ALERT "Bye bye...\n");
}

module_init(hello_init);
module_exit(hello_exit);

MODULE_LICENSE(DRIVER_LICENSE);
MODULE_AUTHOR(DRIVER_AUTHOR);
MODULE_DESCRIPTION(DRIVER_DESC);
