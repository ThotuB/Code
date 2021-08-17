#include <errno.h>
#include <stdio.h>

int main() {
    FILE *fin, *fout;

    fin = fopen("IO/in.txt", "r");
    fout = fopen("IO/out.txt", "w");

    if (!fin || !fout) {
        perror("error on open");
        return errno;
    }

    char c;
    while ((c = fgetc(fin)) != EOF && c != '\n') {
        fprintf(fout, "%c", c + 6);
    }

    if (fclose(fin) || fclose(fout)) {
        perror("error on close");
        return errno;
    }

    /// fopen( FILE*, "rwa +bx") - read, write, append --- both IO, binary, exclusive
    //        -> success: FILE* (!0)
    //        -> error: NULL(0)

    /// fclose( FILE* )
    //        -> success: 0
    //        -> error: EOF(!0)

    /// fscanf( FILE*, "%...%...", ... , ... )
    /// fprintf( FILE*, "text %...", ... )

    /// fgetc( FILE* ) -> gets 1st char in stream
    /// ungetc( int c, FILE* ) -> ungets char into stream

    /// feof( FILE* )
    //        -> at EOF: !0
    //        -> not at EOF: 0

    /// ferror ( FILE* )
    //        -> error: !0
    //        -> no error: 0

    return 0;
}
