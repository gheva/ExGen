#ifndef MATHEX_MULTIPLYBY_H__
#define MATHEX_MULTIPLYBY_H__

#include "level.h"
#include "randnum.h"

namespace mathex
{

/**
  \class MultiplyBy multiplyby.h "mathex/multiplyby.h"
  \ingroup mathex
  \brief Generates multiplication execises with a given left operand

  This class is intended to be proxied when we get to multiplacation of two random digits. This will be done by setting the left operand using the set_left method with a randomly generated number, the MultiplyBy object will handle the right operand.

  Setting the mixit flag, by calling the mix_it method, will result in the left and right operands being swapped randomly.
  */
class MultiplyBy : public xgen::Level
{
public:
  MultiplyBy(unsigned int left, bool mixit=false, unsigned int limit=9);
  virtual ~MultiplyBy();
  void set_left(unsigned int left);
  virtual std::unique_ptr<xgen::Exercise> generate() override;
private:
  RandNum rand_;
  RandNum should_mix_;
  unsigned int left_;
  bool mixit_;
};

} // namespace

#endif // MATHEX_MULTIPLYBY_H__

/* vim: set cindent sw=2 expandtab : */

