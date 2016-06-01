/*
 * InputPaths.h
 *
 *  Created on: 23 Oct 2015
 *      Author: hieu
 */

#pragma once

#include <vector>
#include "../InputPathsBase.h"
#include "../legacy/Matrix.h"

namespace Moses2
{

class Sentence;
class System;

namespace SCFG
{
class InputPath;

class InputPaths: public InputPathsBase
{
  friend std::ostream& operator<<(std::ostream &, const SCFG::InputPaths &);

public:
  void Init(const InputType &input, const ManagerBase &mgr);

  const Matrix<InputPath*> &GetMatrix() const
  {
    return *m_matrix;
  }

protected:
  Matrix<InputPath*> *m_matrix;

};

}
}

