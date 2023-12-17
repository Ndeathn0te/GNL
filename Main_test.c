#include "get_next_line_bonus.h"
#include <fcntl.h>  // Incluye las definiciones para el uso de 'open'
#include <stdio.h>  // Incluye las definiciones para el uso de 'printf'
#include <unistd.h> // Incluye las definiciones para el uso de 'close' y 'read'

// para compilar: gcc Main_test.c get_next_line.c get_next_line_utils.c -o gnl_program
// para testar: ./gnl_program GNL_TEXT.txt
// para compilar con diferentes buffer_size:
// gcc -Wall -Werror -Wextra-D BUFFER_SIZE=42 Main_test.c get_next_line_bonus.c get_next_line_utils_bonus.c -o gnl_test

// Función para leer y mostrar el contenido de un archivo
void	test_file_read(const char *filename)
{
	char	*line;

	int fd = open(filename, O_RDONLY); // Abre el archivo para lectura
	if (fd < 0) // Verifica si el archivo se abrió correctamente
	{
		perror("Error al abrir el archivo");
			// Imprime un mensaje de error si falla
		return ;                              // Sale de la función
	}
	printf("Leyendo archivo: %s\n", filename);
		// Indica qué archivo se está leyendo
	while ((line = get_next_line(fd)) != NULL) // Lee el archivo línea por línea
	{
		printf("%s", line); // Imprime la línea leída
		free(line);         // Libera la memoria de la línea leída
	}
	close(fd); // Cierra el archivo
}

// Función para leer y mostrar el contenido de stdin (entrada estándar)
void	test_stdin_read(void)
{
	char	*line;

	printf("Leyendo desde stdin (Ctrl-D para terminar):\n");
	while ((line = get_next_line(STDIN_FILENO)) != NULL)
	// Lee desde stdin línea por línea
	{
		printf("%s", line); // Imprime la línea leída
		free(line);         // Libera la memoria de la línea leída
	}
}

// Función main que decide si leer de un archivo o de stdin
int	main(int argc, char **argv)
{
	if (argc > 1)
		test_file_read(argv[1]); // Si se proporciona un argumento,
			lee de un archivo
	else
		test_stdin_read(); // Si no, lee de stdin
	return (0); // Finaliza el programa
}
