using System;
using System.Threading;
using Complex = System.Numerics.Complex;
using SixLabors.ImageSharp;
using SixLabors.ImageSharp.PixelFormats;

namespace Mandelbrot;

class Program{
	static Image<Rgba32> img;
	static int tries;
	static int y;

	static void Main(string[] args){
		if(args.Length < 4){
			Console.WriteLine("Usage:\n [Tries] [Images side length] [Output path] [Threads]");
			return;
		}

		img = new Image<Rgba32>(int.Parse(args[1]), int.Parse(args[1]));
		tries = int.Parse(args[0]);

		y = 0;

		Thread[] ts = new Thread[int.Parse(args[3]) - 1];
		for(int i = 0; i < ts.Length; i++){
			ts[i] = new Thread(new ThreadStart(Calculate));
			ts[i].Start();
			Console.WriteLine("Started thread " + i);
		}
		Console.WriteLine("Starting thread " + ts.Length);
		Calculate();
		
		bool allQuit = false;
		while(!allQuit){
			allQuit = true;
			for(int i = 0; i < ts.Length; i++){
				allQuit = allQuit && !ts[i].IsAlive;
			}
		}
		Console.WriteLine("All threads finished ; Saving image");

		img.Save(args[2]);
		Console.WriteLine("Saved image");
		return;
	}

	static void Calculate(){
		while(y < img.Height){
			int ly = y;
			y++;

			for(int lx =0; lx < img.Width; lx++){
				Complex z = new Complex(-2 + (lx * 4 / (double)(img.Width - 1)), -2 + (ly * 4 / (double)(img.Height - 1)));
				Complex c = z;
				int triesNeeded = 0;
				while(c.Magnitude <= 2 && triesNeeded < tries){
					c = c * c + z;
					triesNeeded++;
				}
				if(c.Magnitude <= 2) img[lx, ly] = Rgba32.ParseHex("ffffff");
				else img[lx, ly] = Rgba32.ParseHex("000000");
			}

			Console.WriteLine("Finished line " + ly);
		}
	}
}
