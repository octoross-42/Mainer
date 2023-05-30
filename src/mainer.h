/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainer.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: octoross <octoross@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 02:00:39 by octoross          #+#    #+#             */
/*   Updated: 2023/05/30 11:01:00 by octoross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAINER_H

#define MAINER_H

#define ARGS_IN '['
#define ARGS_OUT ']'
#define ARGS_SEP ' '
#define ARGS_PRECISE_TYPE ':'
#define ARGS_CONTAINER '"'

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

// args_handling

// buffer_formating

char	*remove_comments(char *buffer);
char	*space_around_array_type(char *buffer);

// file_handling

char	*functionName_of_path(char *fileName);
bool	c_file(char *fileName);
char	*file_path_of(char pwd[1024], char *fileName);
char	*formated_buffer(char *buffer);
char	*get_file_buffer(FILE **file);
size_t	file_size(FILE **file);

// function_analysis

char	*get_function(char *buffer, char *functionName);
char	*get_return_type(char *function);
bool	is_function_present(char *buffer, char *functionName);
char	**get_args_types(char *function, int *nbr_arg);

// types_handling

int	sizeof_datatype(char *type_name);

// utils

char	*slice(char *s, int start, int end);
char	*join(char **split_str, char *space);
char	*join_until(char **split_str, char *space, int until);
char	**split(char *s, char *sep, int *len);
char	*str_without_ft(char *str);
void	free_strs(char **split_str, int len);
bool	chrstr(char c, char *str);
char	*substr(char *str, int start, int end);
int		nbr_occ(char c, char *str);
int		last_occ(char c, char *str);
int		max(int a, int b);
int		min(int a, int b);


// listes chainées ///////////////////////////////////////////////////////////////////////////////

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}			t_list;

t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

//////////////////////////////////////////////////////////////////////////////////////////////////

typedef struct s_arg
{
	char	*library;
	char	*type;
	char	*declaration;
	int		len_declaration;
	char	*free;
	int		len_free;
}			arg;

typedef struct s_main_args
{
	int		nbr_arg;
	t_list	*args_list;
	bool	chiant; //aka faire des [] dans le out pour faire des types persos
	bool	args_to_free;
	bool	library_use;
	t_list	*libraries_used;
}			main_args;

// args_handling /////////////////////////////////////////////////////////////////////////////////

char	*argv_to_args(int argc, char **argv);

typedef struct s_opts
{
	char	args_in;
	char	args_out;
	char	args_sep;
	char	args_precise_type;
	char	args_container;
}			args_opts;

//////////////////////////////////////////////////////////////////////////////////////////////////

// types_handling

int	depth_of(char *type);

#endif