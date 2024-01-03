/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bonus_test.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armgonza <armgonza@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 14:33:38 by armgonza          #+#    #+#             */
/*   Updated: 2024/01/03 20:11:08 by armgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
	// Incluye el encabezado para get_next_line versión bonus
#include <fcntl.h>               // Para utilizar open()
#include <stdio.h>               // Para utilizar printf()
#include <unistd.h>              // Para utilizar close()

// para compilar: gcc -Wall -Werror -Wextra -D BUFFER_SIZE=42 Bonus_test.c get_next_line_bonus.c get_next_line_utils_bonus.c -o gnl_test
// para comprobar: puede cambiarse el buffer size a de 42 a 1 a 1000 etc.
// para compilar con depuracion:
// gcc -g -Wall -Werror -Wextra -D BUFFER_SIZE=42 main.c get_next_line_bonus.c get_next_line_utils_bonus.c -o gnl_test


// Función para probar la lectura de múltiples descriptores de archivo
void multi_fd_test(const char *filename1, const char *filename2, const char *filename3) {
    char *line;
    int fd1 = open(filename1, O_RDONLY);
    int fd2 = open(filename2, O_RDONLY);
    int fd3 = open(filename3, O_RDONLY);

    if (fd1 < 0 || fd2 < 0 || fd3 < 0) {
        perror("Error al abrir los archivos");
        return;
    }

    // Lee todo el contenido del primer archivo
    printf("Leyendo archivo: %s\n", filename1);
    while ((line = get_next_line(fd1)) != NULL) {
        printf("%s", line);
        free(line);
    }

    // Lee todo el contenido del segundo archivo
    printf("\nLeyendo archivo: %s\n", filename2);
    while ((line = get_next_line(fd2)) != NULL) {
        printf("%s", line);
        free(line);
    }

    // Lee todo el contenido del tercer archivo
    printf("\nLeyendo archivo: %s\n", filename3);
    while ((line = get_next_line(fd3)) != NULL) {
        printf("%s", line);
        free(line);
    }

    // Cierra los archivos abiertos
    close(fd1);
    close(fd2);
    close(fd3);
}

int	main(int argc, char **argv)
{
	// Verifica si son exactamente tres nombres de archivo
	if (argc == 4)
		multi_fd_test(argv[1], argv[2], argv[3]);
			// Ejecuta la prueba con los archivos dados
	else
		printf(" tres nombres de archivo como argumentos.\n");
	return (0);
}
