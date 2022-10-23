# cquran
This is a very simple program to output ayat (verses) of the Quran on any terminal that supports UTF-8. It requires a text file containing the Quranic corpus, which is to be downloaded from [Tanzil](https://tanzil.net/download/), using the options to include pause marks, sajdah signs and tatweel and simple plain text. This file must be on the same directory as this program's binary.

Users are **strongly** encouraged to check periodically for updates of the Quranic corpus on the Tanzil website linked previously. The version packaged with the source code in this repository is 1.1, released in February 2021.
## Compilation
Since this is a really simple program, you can compile it using `gcc` or your C compiler of preference.
```
gcc quran.c -o quran -O3 -std=c18
```
## Usage
As of now, it can only output a single verse at a time, by passing its surah number and ayah number, respectively, as arguments.
```
quran 2 255
```
The arguments as seen above will display the two hundred fifty-fifth ayah of the second surah.
