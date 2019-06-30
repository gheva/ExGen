#include "digitbydigit.h"

namespace mathex
{

DigitByDigit::DigitByDigit() : generator_(1), rand_(1, 9)
{
}

DigitByDigit::~DigitByDigit()
{
}

std::unique_ptr<xgen::Exercise> DigitByDigit::generate()
{
  unsigned int left(rand_.next_int());
  generator_.set_left(left);
  return generator_.generate();
}

} // namespace

/* vim: set cindent sw=2 expandtab : */

