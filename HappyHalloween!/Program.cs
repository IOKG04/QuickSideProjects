using System;
using System.Drawing;
using Pastel;

namespace HappyHalloween_;

class Program{
    static int[,] img = {
	{1, -1, 1, -1, 1, 1, 1, -1, 1, 1, 1, -1, 1, 1, 1, -1, 1, -1, 1},
	{1, 1, 1, -1, 1, -1, 1, -1, 1, -1, 1, -1, 1, -1, 1, -1, 1, -1, 1},
	{1, -1, 1, -1, 1, 1, 1, -1, 1, 1, 1, -1, 1, 1, 1, -1, -1, 1, -1},
	{1, -1, 1, -1, 1, -1, 1, -1, 1, -1, -1, -1, 1, -1, -1, -1, -1, 1, -1},
	{-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
	{1, -1, 1, -1, 1, 1, 1, -1, 1, -1, -1, -1, 1, -1, -1, -1, 1, 1, 1},
	{1, -1, 1, -1, 1, -1, 1, -1, 1, -1, -1, -1, 1, -1, -1, -1, 1, -1, 1},
	{1, 1, 1, -1, 1, 1, 1, -1, 1, -1, -1, -1, 1, -1, -1, -1, 1, -1, 1},
	{1, -1, 1, -1, 1, -1, 1, -1, 1, 1, 1, -1, 1, 1, 1, -1, 1, 1, 1},
	{-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
	{1, -1, 1, -1, 1, -1, 1, 1, 1, -1, 1, 1, 1, -1, 1, -1, -1, 1, -1},
	{1, -1, 1, -1, 1, -1, 1, 1, 1, -1, 1, 1, 1, -1, 1, 1, -1, 1, -1},
	{1, -1, 1, -1, 1, -1, 1, -1, -1, -1, 1, -1, -1, -1, 1, -1, 1, 1, -1},
	{-1, 1, -1, 1, -1, -1, 1, 1, 1, -1, 1, 1, 1, -1, 1, -1, -1, 1, -1},
    };
    static int[] nodes = new int[266]; //19 * 14
    static int[,] weights = new int[266, 266];

    static void Main(string[] args){
	int repeats = args.Length > 0 ? int.Parse(args[0]) : 1;

	//Set nodes
	for(int i = 0; i < 19; i++){
	    for(int j = 0; j < 14; j++){
		nodes[i + j * 19] = img[j, i];
	    }
	}

	//Set weights
	for(int i = 0; i < 266; i++){
	    for(int j = 0; j < 266; j++){
		if(i == j) {weights[i, j] = 0; continue;}
		weights[i, j] = nodes[i] * nodes[j];
	    }
	}

	//Randomize nodes
	Random r = new Random();
	for(int i = 0; i < 266; i++){
	    nodes[i] = r.Next(0, 2) * 2 - 1;
	}

	do{
	    for(int count = 0; count < repeats; count++){
		//Calculate some note
		int n = r.Next(0, 266);
		int s = 0;
		for(int i = 0; i < 266; i++){
			s += weights[n, i] * nodes[i];
		}
		nodes[n] = s >= 0 ? 1 : -1;
	    }

	    //Print current state
	    Console.Clear();
	    for(int i = 0; i < 14; i++){
		Console.SetCursorPosition(0, i);
		for(int j = 0; j <  19; j++){
		    Console.Write(" ".PastelBg(nodes[i * 19 + j] >= 0 ? Color.White : Color.Black));
		}
	    }
	} while(Console.ReadKey(true).KeyChar.ToString().ToLower() != "q");
    }
}
