# Compile c
gcc -O3 -shared -o dlls/print.dll c/print.c

# Run c#
dotnet run
