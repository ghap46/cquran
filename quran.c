#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>
// This array stores the number of ayat in a given surah.
// Naturally, for a surah of number n, the index of the number
// of ayat in it will be n - 1.
const unsigned short int ayat[] = 
{
    7, 286, 200, 176, 120, 165, 206,
    75, 129, 109, 123, 111, 43, 52, 99,
    128, 111, 110, 98, 135, 112, 78,
    118, 64, 77, 227, 93, 88, 69, 60,
    34, 30, 73, 54, 45, 83, 182, 88,
    75, 85, 54, 53, 89, 59, 37, 35,
    38, 29, 18, 45, 60, 49, 62, 55,
    78, 96, 29, 22, 24, 13, 14, 11,
    11, 18, 12, 12, 30, 52, 52, 44,
    28, 28, 20, 56, 40, 31, 50, 40,
    46, 42, 29, 19, 36, 25, 22, 17,
    19, 26, 30, 20, 15, 21, 11, 8,
    8, 19, 5, 8, 8, 11, 11, 8, 3, 9,
    5, 4, 7, 3, 6, 3, 5, 4, 5, 6
};
// This array stores the total number of ayat before the
// beginning (first ayah) of a given surah. It follows
// the same indexing scheme of the previous array. That
// way, the surah of number 3 will have
// ayatbeforesurah[2] ayat before it.
const unsigned short int ayatbeforesurah[] = 
{
    0, 7, 293, 493, 669, 789, 954, 1160,
    1235, 1364, 1473, 1596, 1707, 1750,
    1802, 1900, 2029, 2140, 2250, 2348,
    2483, 2595, 2673, 2791, 2855, 2932,
    3159, 3252, 3340, 3409, 3469, 3503,
    3533, 3606, 3660, 3705, 3788, 3970,
    4058, 4133, 4218, 4272, 4325, 4414,
    4473, 4510, 4545, 4583, 4612, 4630,
    4675, 4735, 4784, 4846, 4901, 4979,
    5075, 5104, 5126, 5150, 5164, 5177,
    5188, 5199, 5217, 5229, 5241, 5271,
    5323, 5375, 5419, 5447, 5475, 5495,
    5551, 5591, 5622, 5672, 5712, 5758,
    5800, 5829, 5848, 5884, 5909, 5931,
    5948, 5967, 5993, 6023, 6043, 6058,
    6079, 6090, 6098, 6106, 6125, 6130,
    6138, 6146, 6157, 6168, 6176, 6179,
    6188, 6193, 6197, 6204, 6207, 6213,
    6216, 6221, 6225, 6230
};
int main(int argc, char* argv[])
{
    // Setting locale to print UTF-8.
    setlocale(LC_CTYPE, "");
    if(argc != 3)
    {
        printf("No surah and verse number was provided, halting.\n"
        "Usage: quran <surah number> <ayah number>\n");
        return -1;
    }
    if(atoi(argv[1]) < 1 || atoi(argv[1]) > 114)
    {
        printf("Invalid surah number passed, halting.\n"
        "Usage: quran <surah number> <ayah number>\n");
        return -2;
    }
    if(atoi(argv[2]) < 1 || atoi(argv[2]) > ayat[atoi(argv[1]) - 1])
    {
        printf("Invalid ayah requested, halting.\n"
        "Usage: quran <surah number> <ayah number>\n");
        return -3;
    }
    FILE *quranfile = fopen("quran-simple-plain.txt", "rb");
    if(quranfile == NULL)
    {
        printf("The Quran file wasn't found on this directory"
        ", or you don't the required permissions to access it. If you "
        "wish to download it, visit https://tanzil.net/download/ and "
        "download the simple plain version with pause marks, sajdah "
        "signs and tatweel, then move the file to this directory. "
        "The filename should be quran-simple-plain.txt.\n");
        return -1;
    }
    wchar_t str[2048]; // Buffer for the wide characters
    for(unsigned short int i = 0; i < ayatbeforesurah[atoi(argv[1]) - 1]\
     + atoi(argv[2]); ++i)
    {
        fgetws(str, sizeof(str), quranfile);
    }
    wprintf(L"%ls", str);
    fclose(quranfile);
    return 0;
}