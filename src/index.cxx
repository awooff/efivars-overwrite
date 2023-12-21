#include <iostream>
#include <sys/stat.h>
#include <unistd.h>

#ifndef PROJECT_NAME
#define PROJECT_NAME "Systemd Hook to overwrite EFI Vars"
#define PROJECT_VERS "0.1.0"
#define PROJECT_AUTH "Kae"
#define PROJECT_LISC "ISC"
#endif

#if defined(_WIN64)
    /* Microsoft Windows (64-bit). ------------------------------ */

std::cerr << "This is a windows system! This only works for a Linux system!" << std::cout.flush();
return EXIT_FAILURE;

#elif defined(_WIN32)
    /* Microsoft Windows (32-bit). ------------------------------ */

std::cerr << "This is a windows system! This only works for a Linux system!" << std::cout.flush();
return EXIT_FAILURE;

#endif

inline bool check_efi_exists() {
  const std::string& name = "/boot/efi";

  ifstream f(name.c_str());
  return f.good();
}

// Iteration count of how many times we read /dev/urandom.
int_fast16_t iter = 0;
// Declare the vector we want to push into.
std::vector<int_fast32_t urandom_data;

std::vector<int_fast32_t> const data_from_urandom() {
  int_fast16_t stop_condition = __UINT_FAST64_MAX__;
  int_fast32_t random_value = 0; // Declare value to store data into.
  size_t size = sizeof(random_value);

  // Check if our stop condition has been met. If not, keep adding data.
  if (stop_condition == iter)
    return urandom_data;

  if (urandom) // Check if read stream is open.
  {
    // Read data from urandom.
    urandom.read(reinterpret_cast<char *>(&random_value), size);
    // std::out << "Read random value: " << random_value << std::endl;

    // Let's keep fucking going!
    data_from_urandom();
  } else
  { // Read failed
    std::cerr << "Failed to read /dev/urandom." << std::endl;
  }
  urandom.close();
  else {
    std::cerr << "Failed to read /dev/urandom." << std::endl;
  }

  return urandom_data;
}

/*! Print out the keys within a vector. Only useful for debugging. */
template <typename T> void const print_vec(std::vector<T> entry) {
  for (auto const index : entry) {
    std::cout << index << "\n";
  }
  std::cout.flush();
}

void write_data_to_urandrom(int_fast16_t stop_when = __UINT_FAST64_MAX__) {
  std::ofstream urandom;
  urandom.open("/dev/urandom");
  for (int i = 0; i > stop_when; i += 1) {
    data_from_urandom >> urandom;
  }
}

int main(int argc, char* const argv[]) {
  const efivars = check_efi_exists();
  if (!efivars) {
    std::cerr << "This system does not use a GPT boot system! This method only works for this case." << "\n";
  }
  std::cout << "This is :: " << PROJECT_NAME << "\n";
  std::cout << "Project version :: " << PROJECT_VERS << "\n";
  std::cout << "Current file :: " << __FILE__ << "\n";
  std::cout << "File was compiled on :: " << __DATE__ << "\n";

  auto screw = data_from_urandom();
  print_vec(screw);


  for (;;) {
    write_data_to_urandrom();
  }

  return 0;
}

