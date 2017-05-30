#include <dirent.h>
#include <stdio.h>
#include <sys/stat.h>

int main()
{
	void 			*dirp;
	struct dirent	*dp;
	struct stat		fileStat;

	dirp = opendir(".");
	while ((dp = readdir(dirp)))
	{
		printf("%s\n", dp->d_name);
		stat(dp->d_name, &fileStat);
		printf("Information for %s\n",dp->d_name);
		printf("---------------------------\n");
		printf("File Size: \t\t%d bytes\n",fileStat.st_size);
		printf("Number of Links: \t%d\n",fileStat.st_nlink);
		printf("File inode: \t\t%d\n",fileStat.st_ino);

		printf("User-id : %u\n", fileStat.st_uid);

		printf("st.mode : %u S_IXUSR : %u S_IXGRP : %u\n", fileStat.st_mode, S_IXUSR, S_IXGRP);
		printf("File Permissions: \t");
		printf( (S_ISDIR(fileStat.st_mode)) ? "d" : "-");
		printf( (fileStat.st_mode & S_IRUSR) ? "r" : "-");
		printf( (fileStat.st_mode & S_IWUSR) ? "w" : "-");
		printf( (fileStat.st_mode & S_IXUSR) ? "x" : "-");
		printf( (fileStat.st_mode & S_IRGRP) ? "r" : "-");
		printf( (fileStat.st_mode & S_IWGRP) ? "w" : "-");
		printf( (fileStat.st_mode & S_IXGRP) ? "x" : "-");
		printf( (fileStat.st_mode & S_IROTH) ? "r" : "-");
		printf( (fileStat.st_mode & S_IWOTH) ? "w" : "-");
		printf( (fileStat.st_mode & S_IXOTH) ? "x" : "-");
		printf("\n\n");

		printf("The file %s a symbolic link\n", (S_ISLNK(fileStat.st_mode)) ? "is" : "is not");
	}
	return (0);
}
