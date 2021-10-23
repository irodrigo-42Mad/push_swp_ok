/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftprimary.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irodrigo <irodrigo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 11:02:12 by irodrigo          #+#    #+#             */
/*   Updated: 2021/10/23 13:30:27 by irodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FTPRIMARY_H
# define FTPRIMARY_H

# include <stdlib.h>
# include <limits.h>
# include <string.h>
# include "./libft/libft.h"

/*
**	BOOLEAN type definition and constant values
*/
typedef enum e_boolean
{
	FALSE,
	TRUE
}	t_boolean;

typedef t_boolean	t_bool;

/*
**	CONSTANTS general constants
*/

# define ACTIVE			1
# define INACTIVE		0
# define BUFFER_SIZE	1
# define FILE_DSC		4096
# define L_EOF 			'\n'

// Pos antiguo n_val
// val antiguo value
// seg_lim antiguo chunk_limit
typedef struct s_data {
	int		pos;
	int		val;
	short	seg_lim;
	void	*next;		
}			t_data;

/*
** STACKS Actions and operations
*/
void	push(t_data **my_stack, t_data **dest);
void	push_a(t_data **stk_b, t_data **stk_a);
void	push_b(t_data **stk_a, t_data **stk_b);

void	swap(t_data **my_stack);
void	swap_a(t_data **stk_a, t_data **stk_b);
void	swap_b(t_data **stk_a, t_data **stk_b);
void	swap_ab(t_data **stk_a, t_data **stk_b);

void	rotate(t_data **stk);
void	rotate_a(t_data **stk_a, t_data **stk_b);
void	rotate_b(t_data **stk_a, t_data **stk_b);
void	rotate_ab(t_data **stk_a, t_data **stk_b);

void	rev_rot(t_data **stk);
void	rev_rot_a(t_data **stk_a, t_data **stk_b);
void	rev_rot_b(t_data **stk_a, t_data **stk_b);
void	rev_rot_ab(t_data **stk_a, t_data **stk_b);

/*
** PRAGMA GENERAL functions
*/
void	checker(t_data *stk_a, t_data *stk_b);
void	ft_sort(t_data **a, t_data **b, t_data *oper);
int		get_next_line(int fd, char **line);
t_data	*ft_getlist_instr(void);
void	ft_set_next_instr(char *el, t_data **ins_lst);

/*
** PUSH SWAP general use functions for sorting data elements
*/
void	ft_sort_algrthm(t_data **el);
void	ft_push_swap_lite(t_data **a, t_data **b, int len);
void	ft_push_swap_lng(t_data **a, t_data **b, int len);
void	ft_sort_three(t_data **a, t_data **b);

/*
** SORT TYPES functions of stack sorting types
*/
void	ft_b_split(int n_elm, t_data **a, t_data **b);
void	ft_tiny_b_split(int n_elm, t_data **a, t_data **b);
void	ft_a_split(int n_elm, t_data **a, t_data **b);
void	ft_rev_split(int n_elm, t_data **a, t_data **b);
t_data	*ft_get_axis(int n_elm, t_data **stk);
void	ft_rot_axis_max(int n_elm, t_data **a,
			t_data **b,	t_data *max);
void	ft_split_rot_b(int n_elm, t_data **a, t_data **b);
void	ft_stk_rotate_bk(int rot_el, t_data **a, t_data **b);
void	ft_max_axisrot(t_data **a, t_data **b);
void	ft_restore_back(int n_elm, t_data **a, t_data **b);

/*
** PUSH SWAP Auxiliary internal functions
*/
short	ft_has_sorted(t_data *start, int length, short order);
void	ft_new_sglimit(t_data *stk, t_data *lim);
void	ft_set_sgimit(t_data **b, int *lim_set_state);
int		ft_segment_len(t_data *a);

/*
** SORTING general sorting stack functions
*/
t_data	*ft_merge(t_data *stk_a, t_data *stk_b);
t_data	*ft_merge_sort(t_data *stk_a);
t_data	*ft_stack_split(t_data **stk, int len);
void	ft_remv_elm_a(t_data **stk_a, t_data **stk_b, int *a_len);
void	ft_remv_elm_b(t_data **stk_a, t_data **stk_b);
short	ft_order_two(t_data **stk_a, t_data **stk_b);
void	ft_next_stkelm(char *nptr, long *num);

/*
** GENERAL Stack utils
*/
void	ft_replace(t_data *src, t_data *dest, int val);
t_data	*ft_init_stk(char **elms);
t_data	*ft_stack_pop(t_data *first, int pos);
t_data	*ft_partial_sort_stk(t_data *first, int len);
void	ft_addlst(t_data **stk, int val);
void	ft_hasdupl(t_data *stk, int val);
t_data	*ft_getlast(t_data *stk);
t_data	*ft_goto_el(t_data *stk, short pos);
int		ft_lstlength(t_data *stk);

//void	lst_print(char *msg, t_data *stack);
//void	lst_print_norm(char *msg, t_data *stack);
//int		lst_len_end(t_data *stack, t_data *end);
//t_data	*lst_last(t_data *stack);

/*
** AUXILIAR control functions
*/
void	ft_set_string(char *s[4096], char *buffer, int fd, char *aux);
short	ft_exist_left_val(t_data *b, t_data *axis);
int		ft_atoi_cnv(char *nptr);
short	ft_min_max(t_data *stk);

/*
** ERROR Error control functions used
*/
void	ft_write_error(char *err_tit, char *errmsg);
int		ft_put_error(char *err_tit, char *errmsg, int err_n);

/*
** CLEAN malloc clean functions
*/
void	ft_clean_table(char **str);

#endif
