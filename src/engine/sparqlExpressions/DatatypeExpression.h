//  Copyright 2022, University of Freiburg,
//                  Chair of Algorithms and Data Structures.
//  Author: Johannes Kalmbach <kalmbacj@cs.uni-freiburg.de>

#pragma once

#include <string>

#include "engine/sparqlExpressions/SparqlExpression.h"

namespace sparqlExpression {
class DatatypeExpression : public SparqlExpression {
 private:
  SparqlExpression::Ptr child_;

 public:
  // `child` must be a `VariableExpression`.
  DatatypeExpression(SparqlExpression::Ptr child);

  ExpressionResult evaluate(EvaluationContext* context) const override;
};
}  // namespace sparqlExpression
