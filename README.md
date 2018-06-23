# Libft
My very own 42 library of basic C functions :smile:

### Ft_libft is made up of:
* [data strucutres:](https://github.com/psprawka/Libft/tree/master/srcs/data_structures)
* 	[queues management,](https://github.com/psprawka/Libft/tree/master/srcs/data_structures/queue)
* 	[linked-list management.](https://github.com/psprawka/Libft/tree/master/srcs/data_structures/list)
* [memory manipulation,](https://github.com/psprawka/Libft/tree/master/srcs/memory)
* [string manipulation,](https://github.com/psprawka/Libft/tree/master/srcs/string)
* [numeric functions,](https://github.com/psprawka/Libft/tree/master/srcs/numeric)
* [input/output operations,](https://github.com/psprawka/Libft/tree/master/srcs/io)
* [additional no-category tools.](https://github.com/psprawka/Libft/tree/master/srcs/tools)

# !WARNING!
DO NOT USE FT_PRINTF; Function ft_itoa has been changed from heap to stack memory, thus since ft_printf was coded according to "old" ft_itoa version, it tries to free stack pointer. I'll fix it once I have time or once I'll have to 😛