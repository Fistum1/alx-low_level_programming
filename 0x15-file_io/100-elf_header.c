#include <elf.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void check_elf(unsigned char* e_ident1);
void print_magic(unsigned char* e_ident1);
void print_class(unsigned char* e_ident1);
void print_data(unsigned char* e_ident1);
void print_version(unsigned char* e_ident1);
void print_abi(unsigned char* e_ident1);
void print_osabi(unsigned char* e_ident1);
void print_type(unsigned int e_type1, unsigned char* e_ident1);
void print_entry(unsigned long int e_entry1, unsigned char* e_ident1);
void close_elf(int elf);

/**
 * check_elf - Checks if a file is ELF file.
 * @e_ident1: A pointer to an array containing the ELF magic numbers.
 * Description: If the file is not an ELF file - exit code 98.
 */
void check_elf(unsigned char* e_ident1)
{
	int index;

	for (index = 0; index < 4; index++)
	{
		if (e_ident1[index] != 127 &&
			e_ident1[index] != 'E' &&
			e_ident1[index] != 'L' &&
			e_ident1[index] != 'F')
		{
			dprintf(STDERR_FILENO, "Error: Not an ELF file\n");
			exit(98);
		}
	}
}

void print_magic(unsigned char* e_ident1)
{
	int index;

	printf("  Magic:   ");

	for (index = 0; index < EI_NIDENT; index++)
	{
		printf("%02x", e_ident1[index]);

		if (index == EI_NIDENT - 1)
			printf("\n");
		else
			printf(" ");
	}
}

/**
 * print_class - Prints the class of an ELF header.
 * @e_ident1: A pointer to an array containing the ELF class.
 **/
void print_class(unsigned char* e_ident1)
{
	printf("  Class:                             ");

	switch (e_ident1[EI_CLASS])
	{
	case ELFCLASSNONE:
		printf("none\n");
		break;
	case ELFCLASS32:
		printf("ELF32\n");
		break;
	case ELFCLASS64:
		printf("ELF64\n");
		break;
	default:
		printf("<unknown: %x>\n", e_ident1[EI_CLASS]);
	}
}
/**
 * print_data - Prints the data of an ELF header.
 * @e_ident1: A pointer to an array containing the ELF class.
 */
void print_data(unsigned char* e_ident1)
{
	printf("  Data:                              ");

	switch (e_ident1[EI_DATA])
	{
	case ELFDATANONE:
		printf("none\n");
		break;
	case ELFDATA2LSB:
		printf("2's complement, little endian\n");
		break;
	case ELFDATA2MSB:
		printf("2's complement, big endian\n");
		break;
	default:
		printf("<unknown: %x>\n", e_ident1[EI_CLASS]);
	}
}
/**
 * print_version - Prints the version of an ELF header.
 * @e_ident1: A pointer to an array containing the ELF version.
 */
void print_version(unsigned char* e_ident1)
{
	printf("  Version:                           %d",
		e_ident1[EI_VERSION]);

	switch (e_ident1[EI_VERSION])
	{
	case EV_CURRENT:
		printf(" (current)\n");
		break;
	default:
		printf("\n");
		break;
	}
}
/**
 * print_osabi - Prints the OS/ABI of an ELF header.
 * @e_ident1: A pointer to an array containing the ELF version.
 */
void print_osabi(unsigned char* e_ident1)
{
	printf("  OS/ABI:                            ");

	switch (e_ident1[EI_OSABI])
	{
	case ELFOSABI_NONE:
		printf("UNIX - System V\n");
		break;
	case ELFOSABI_HPUX:
		printf("UNIX - HP-UX\n");
		break;
	case ELFOSABI_NETBSD:
		printf("UNIX - NetBSD\n");
		break;
	case ELFOSABI_LINUX:
		printf("UNIX - Linux\n");
		break;
	case ELFOSABI_SOLARIS:
		printf("UNIX - Solaris\n");
		break;
	case ELFOSABI_IRIX:
		printf("UNIX - IRIX\n");
		break;
	case ELFOSABI_FREEBSD:
		printf("UNIX - FreeBSD\n");
		break;
	case ELFOSABI_TRU64:
		printf("UNIX - TRU64\n");
		break;
	case ELFOSABI_ARM:
		printf("ARM\n");
		break;
	case ELFOSABI_STANDALONE:
		printf("Standalone App\n");
		break;
	default:
		printf("<unknown: %x>\n", e_ident1[EI_OSABI]);
	}
}
/**
 * print_type - Prints the type of an ELF header.
 * @e_type1: ELF type.
 * @e_ident1: A pointer to an array containing the ELF class.
 */
void print_type(unsigned int e_type1, unsigned char* e_ident1)
{
	if (e_ident1[EI_DATA] == ELFDATA2MSB)
		e_type1 >>= 8;

	printf("  Type:                              ");

	switch (e_type1)
	{
	case ET_NONE:
		printf("NONE (None)\n");
		break;
	case ET_REL:
		printf("REL (Relocatable file)\n");
		break;
	case ET_EXEC:
		printf("EXEC (Executable file)\n");
		break;
	case ET_DYN:
		printf("DYN (Shared object file)\n");
		break;
	case ET_CORE:
		printf("CORE (Core file)\n");
		break;
	default:
		printf("<unknown: %x>\n", e_type1);
	}
}
/**
 * print_abi - Prints the ABI version of an ELF header.
 * @e_ident1: A ptr to an array containing the ELF ABI version.
 */
void print_abi(unsigned char* e_ident1)
{
	printf("  ABI Version:                       %d\n",
		e_ident1[EI_ABIVERSION]);
}
/**
 * print_entry - Prints the entry point of an ELF header.
 * @e_entry1: The address of the ELF entry point.
 * @e_ident1: A pointer to an array containing the ELF class.
 */
void print_entry(unsigned long int e_entry1, unsigned char* e_ident1)
{
	printf("  Entry point address:               ");

	if (e_ident1[EI_DATA] == ELFDATA2MSB)
	{
		e_entry1 = ((e_entry1 << 8) & 0xFF00FF00) |
			((e_entry1 >> 8) & 0xFF00FF);
		e_entry1 = (e_entry1 << 16) | (e_entry1 >> 16);
	}

	if (e_ident1[EI_CLASS] == ELFCLASS32)
		printf("%#x\n", (unsigned int)e_entry1);

	else
		printf("%#lx\n", e_entry1);
}
/**
 * main - Displays the information contained in the ELF header at the start of an ELF file.
 * @argc: Number of arguments supplied to the program.
 * @argv: Array of ptrs to the arguments.
 * Return: 0 on success.
 *
 * Description: If the file is not an ELF File or the function fails - exit code 98.
 */
int main(int __attribute__((__unused__)) argc1, char* argv1[])
{
	Elf64_Ehdr* header;
	int o, r;

	o = open(argv1[1], O_RDONLY);
	if (o == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv1[1]);
		exit(98);
	}
	header = malloc(sizeof(Elf64_Ehdr));
	if (header == NULL)
	{
		close_elf(o);
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv1[1]);
		exit(98);
	}
	r = read(o, header, sizeof(Elf64_Ehdr));
	if (r == -1)
	{
		free(header);
		close_elf(o);
		dprintf(STDERR_FILENO, "Error: `%s`: No such file\n", argv1[1]);
		exit(98);
	}

	check_elf(header-> e_ident);
	printf("ELF Header:\n");
	print_magic(header->e_ident);
	print_class(header->e_ident);
	print_data(header->e_ident);
	print_version(header->e_ident);
	print_osabi(header->e_ident);
	print_abi(header->e_ident);
	print_type(header->e_type, header->e_ident);
	print_entry(header->e_entry, header->e_ident);

	free(header);
	close_elf(o);
	return (0);
}

/**
 * close_elf - Closes an ELF file.
 * @elf: File descriptor of the ELF file.
 * Description: If the file cannot be closed - exit code 98.
 */
void close_elf(int elf)
{
	if (close(elf) == -1)
	{
		dprintf(STDERR_FILENO,
			"Error: Can't close fd %d\n", elf);
		exit(98);
	}
}
