#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/proc_fs.h>
#include <asm/uaccess.h>

#define DRIVER_AUTHOR "Loicia et Alix"
#define DRIVER_DESC "Chenillard Module"
#define DRIVER_LICENSE "GPL"
#define ADDR_REG_LED 0xFF203000

static int vitesse;
static char * pattern  = "101000101";


module_param(vitesse, int, 0);
MODULE_PARM_DESC(vitesse, "La vitesse de ce module");

static ssize_t chenillard_proc_read(struct file *file, char __user * buffer, size_t count, loff_t * ppos)
{
    int errno = 0;
    int copy;
    if((copy=copy_to_user(buffer, pattern, strlen(pattern)+1)))
    {
        errno = -EFAULT;
    }
    printk( KERN_INFO "message read, %d, %p\n", copy, buffer);
    return count-copy;
}

static ssize_t chenillard_proc_write(struct file *file, char __user * buffer, size_t count, loff_t * ppos)
{
   // int len = count;
    printk(KERN_INFO "message received\n");
    if((copy_from_user(pattern,buffer,count)))
    {
        return -EFAULT;
    }
    pattern[count]='\0';
    //int size_of_pattern = strlen(pattern);
    printk(KERN_INFO "New message : %s\n", pattern);
    return count;
}

static const struct file_operations chenillard_proc_fops = {
    .owner = THIS_MODULE,
    .read = chenillard_proc_read,
    .write = chenillard_proc_write
    //.open = chenillard_proc_open
};

int chenillard_init(void)
{
    //uint32_t * p;
	printk(KERN_INFO "Lancement du chenillard !\n");
	printk(KERN_DEBUG "la vitesse du chenillard est =%d\n", vitesse);
    struct proc_dir_entry *parent;
    struct proc_dir_entry *enfant;
	parent = proc_mkdir("ensea", NULL);
    enfant = proc_create("chenille", 0, parent, &chenillard_proc_fops);

    //fd = open("proc/ensea/chenille", O_RDWR);
    //p = (uint32_t*)mmap(NULL, 10, PROT_WRITE | PROT_READ, MAP_SHARED, fd, ADDR_REG_LED);
    
    
	return 0;
}

void chenillard_exit(void)
{
	printk(KERN_ALERT "Bye bye...\n");
}

module_init(chenillard_init);
module_exit(chenillard_exit);

MODULE_LICENSE(DRIVER_LICENSE);
MODULE_AUTHOR(DRIVER_AUTHOR);
MODULE_DESCRIPTION(DRIVER_DESC);
