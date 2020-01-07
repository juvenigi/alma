// Copyright © 2017-2018 Martin Ueding <dev@martin-ueding.de>

#pragma once

#include <cstddef>

double constexpr re_min = -1.9;
double constexpr re_max = 1.6;
double constexpr im_min = -1.1;
double constexpr im_max = 1.1;

//size_t constexpr ly = 50 / 2.54 * 50;
size_t constexpr ly = 2200;
size_t constexpr lx = 2500;

double constexpr d = (im_max - im_min) / ly;
//size_t constexpr lx = (re_max - re_min) / d;

size_t constexpr sites = lx * ly;

int constexpr max_iter = 1000; // 1024
double constexpr radius = 4; //5

size_t constexpr veclen = 4;
size_t constexpr blocks_x = lx / veclen;
