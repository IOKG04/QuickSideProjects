using System;
using System.Numerics;

namespace CirclePartCalculator;

public class Program{
    public static int Main(string[] args){
	if(args.Length < 2){
	    Console.WriteLine("Error 1: Not enough arguments\n\nUsage:\n [Dots] [Radius] ([Round 1?0] [Accuracy])");
	    return 1;
	}

	int dots = int.Parse(args[0]);
	int radius = int.Parse(args[1]);
	bool round = false;
	if(args.Length >= 3) round = int.Parse(args[2]) == 1;
	int accuracy = 3;
	if(args.Length >= 4) accuracy = int.Parse(args[3]);
	string format = "0.";
	for(int i = 0; i < accuracy; i++) format += "#";

	for(int i = 0; i < dots; i++){
	    Complex c = new Complex(Math.PI * 2 * i / dots, 0);
	    c = Complex.Exp(c * Complex.ImaginaryOne) * radius;
	    if(round) c = new Complex(Math.Round(c.Real), Math.Round(c.Imaginary));
	    Console.WriteLine("X: " + c.Real.ToString(format) + "\tY: " + c.Imaginary.ToString(format));
	}

	return 0;
    }
}
