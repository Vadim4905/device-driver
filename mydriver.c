/*  My first device driver.  This is a minimal kernel loadable module with a single file operation for read */
#include <linux/init.h>
#include <linux/module.h>



#define DEVICE_NAME "mydriver"
#define MY_MAJOR 42

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Generic device driver");




static ssize_t my_read (struct file *f, char *s, size_t z, loff_t *l)
{
    memcpy (s, "hello", 5);
    return 5;
}

static const struct file_operations fops =
{
    .owner = THIS_MODULE,
    .read = my_read,
};

static int my_init(void)
{
    register_chrdev (MY_MAJOR, DEVICE_NAME, &fops);
    return 0;
}

static void my_exit(void)
{
    unregister_chrdev (MY_MAJOR, DEVICE_NAME);
}

module_init(my_init);
module_exit(my_exit);
