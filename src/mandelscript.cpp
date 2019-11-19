/* really fast and optimized calculation of a mandelbrot set. */

// original code by Martin Ueding <dev@martin-ueding.de>
// code optimization inspired by brucedawson
// https://randomascii.wordpress.com/2011/08/13/faster-fractals-through-algebra/ [visited at 19.11.2019]

// UNI BONN REPRESENT!

#include <omp.h>
#include <memory>
#include <vector>

#define SQ(x) ((x)*(x))

int constexpr dimx = 2500;
int constexpr dimy = 2200;
double constexpr re_min = -1.9;
double constexpr re_max = 0.6;
double constexpr im_min = -1.1;
double constexpr im_max = 1.1;

size_t constexpr max_iter = 1024;
double constexpr radius = 4; // was 5 before some some reason

// AVX instruction set allows you to simultaniously compute 4 floats in one go!
size_t constexpr veclen = 4; // constexpr <=> constant at compile-time, important
size_t constexpr blocks_x = dimx / veclen; // necessary for parallelization


/* Helper functions */
size_t idx(size_t const bx, size_t const y) {
  return y * blocks_x + bx;
}

double get_c_re(size_t const bx, size_t const x) {
  return re_min + (bx * veclen + x) * d;
}

double get_c_im(size_t const y) {
  return im_min + y * d;
}

using namespace std;

/* mandelbrot set begins here */
vector<uint16_t> * mandelscript(int dimx, int dimy, int max_iter,
                               double re_min, double re_max,
                               double im_min, double im_max,){
  vector<uint16_t> escape_iter(dimx * dimy, max_iter);

#pragma omp parallel for collapse(2) // makes it run on all cores (4 in my case)
  for (size_t y = 0; y < ly; ++y) {
    for (size_t bx = 0; bx < blocks_x; ++bx) {
      alignas(veclen * sizeof(bool)) bool finished[veclen] = {false};
      // alignas(veclen * sizeof(bool)) bool written[veclen] = {false};

      alignas(veclen * sizeof(double)) double z_re[veclen] = {0.0};
      alignas(veclen * sizeof(double)) double z_im[veclen] = {0.0};
      alignas(veclen * sizeof(double)) double new_z_re[veclen];
      alignas(veclen * sizeof(double)) double new_z_im[veclen];

      alignas(veclen * sizeof(double)) double c_re[veclen] = {0.0};
      for (size_t v = 0; v < veclen; ++v) {
        c_re[v] = get_c_re(bx, v);
      }
      double c_im = get_c_im(y);

      for (size_t iter = 0; iter < max_iter; ++iter) {
#pragma omp simd aligned(z_re, z_im, new_z_re, new_z_im, finished)
        for (size_t v = 0; v < veclen; ++v) {
          // Apparently this saves up some computation time...
          auto const z_re_sq = SQ(z_re[v]);
          auto const z_im_sq = SQ(z_im[v]);
          auto const z_re_im = z_re[v] + z_im[v];
          auto const abs = z_re_sq + z_im_sq; // we might be doing one iteration too few, but whatevs

          if (!finished[v] && abs > radius) {
            finished[v] = true;
            escape_iter[idx(bx, y) * veclen + v] = iter;
          }

          new_z_re[v] = z_re_sq - z_im_sq + c_re[v];
          new_z_im[v] = SQ(z_re_im) - z_re_sq - z_im_sq + c_im;

          z_re[v] = new_z_re[v];
          z_im[v] = new_z_im[v];
        }

        bool all_finished = true;
        for (size_t v = 0; v < veclen; ++v) {
          all_finished &= finished[v];
        }

        if (all_finished) {
          break;
        }
      }
    }
  }
  return escape_iter;
}
