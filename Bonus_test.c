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
void	multi_fd_test(const char *filename1, const char *filename2,
		const char *filename3)
{
	char	*line;

	int fd1 = open(filename1, O_RDONLY); // Abre el primer archivo para lectura
	int fd2 = open(filename2, O_RDONLY); // Abre el segundo archivo para lectura
	int fd3 = open(filename3, O_RDONLY); // Abre el tercer archivo para lectura
	// Verifica si alguno de los archivos no se pudo abrir
	if (fd1 < 0 || fd2 < 0 || fd3 < 0)
	{
		perror("Error al abrir los archivos"); // Muestra un mensaje de error
		return ;                               
		// Termina la función si hay un error
	}
	// Lee una línea de cada archivo de forma alternativa
	printf("Archivo 1: ");
	line = get_next_line(fd1); // Lee una línea del primer archivo
	if (line)
		printf("%s", line); // Si se leyó una línea, imprímela
	free(line);             // Libera la línea leída
	printf("Archivo 2: ");
	line = get_next_line(fd2); // Lee una línea del segundo archivo
	if (line)
		printf("%s", line); // Si se leyó una línea, imprímela
	free(line);             // Libera la línea leída
	printf("Archivo 3: ");
	line = get_next_line(fd3); // Lee una línea del tercer archivo
	if (line)
		printf("%s", line); // Si se leyó una línea, imprímela
	free(line);             // Libera la línea leída
	// Cierra los archivos abiertos
	close(fd1);
	close(fd2);
	close(fd3);
}

// Función main que ejecuta las pruebas
int	main(int argc, char **argv)
{
	// Verifica si se proporcionaron exactamente tres nombres de archivo
	if (argc == 4)
		multi_fd_test(argv[1], argv[2], argv[3]);
			// Ejecuta la prueba con los archivos dados
	else
		printf("Proporciona exactamente tres nombres de archivo como argumentos.\n");
	return (0); // Finaliza el programa
}
