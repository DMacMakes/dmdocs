#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace ___;

const ___ RANDOMS_NEEDED = 3;

/// Generate a single random integer between 0 and `max`
___ randomInRange(int max)
{
  int result = _;
  int random = _______();

  result = random % (max + 1);
  return( _______ );
}

/// Generate and display random numbers between 0 and `max`
void showRandomsInRange(___ max)
__
  _______ __ "\t Generating random numbers between 0 and " __ max __ "\n";
  int random = 0;

  for (int _ = 0; _ _ RANDOMS_NEEDED; i++)
  {
    _______ = randomInRange(max);      // Farming out the number generation 
    cout << "\t >>>>>>>>>> " << random << "\n";
  }
  ____ << "\n";
  return;
__

___ main()
{
  // Get the time as an int without an error.
  unsigned int seed = (unsigned int)time(0);

  // Seed random number generator with time in seconds
  _______(seed);

  cout << "?????????????????????????????????????????????????????????????????\n";
  cout << "????????????????? Random number generator ???????????????????????\n";
  cout << "?????????????????????????????????????????????????????????????????\n\n";
  // Show some randoms in range 0 - 5,
  _______(5);
  // in range 0-200
  _______(200);
  // and finally 0-19999
  _______(19999);
  
  //// Finished
  _______(0);
}

