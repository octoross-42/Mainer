/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sizeof_datatype.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: octoross <octoross@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 10:29:23 by octoross          #+#    #+#             */
/*   Updated: 2023/05/30 11:02:30 by octoross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mainer.h"

int	sizeof_datatype(char *type_name)
{
	if (!(strcmp(type_name, "void")))
        return sizeof(void);
	else if (!(strcmp(type_name, "char") && strcmp(type_name, "unsigned char")))
        return sizeof(char); 
	else if (!(strcmp(type_name, "short") && strcmp(type_name, "short int")))
        return sizeof(short);
    else if (!(strcmp(type_name, "int")))
        return sizeof(int);
    else if (!(strcmp(type_name, "unsigned int")))
        return sizeof(unsigned int);
    else if (!(strcmp(type_name, "unsigned long") && strcmp(type_name, "unsigned long int")))
        return sizeof(unsigned long);
    else if (!(strcmp(type_name, "unsigned short") && strcmp(type_name, "unsigned short int")))
        return sizeof(unsigned short);
	else if (!(strcmp(type_name, "long") && strcmp(type_name, "long int") && strcmp(type_name, "long long") && strcmp(type_name, "unsigned long long")))
        return sizeof(long);
	else if (!(strcmp(type_name, "float")))
        return sizeof(float);
	else if (!(strcmp(type_name, "double")))
        return sizeof(double);
	else if (!(strcmp(type_name, "long double")))
        return sizeof(long double);
	else if (strstr(type_name, "*"))
		return sizeof(void *);
	else
		return (-1);
}

