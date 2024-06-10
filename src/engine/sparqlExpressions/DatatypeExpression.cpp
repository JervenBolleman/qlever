// Copyright 2024
// University of Freiburg
// Chair of Algorithms and Data Structures
// SIB Swiss Institute of Bioinformatics
// Authors: Jerven Bolleman <Jerven.Bolleman@sib.swiss>

#include "./DatatypeExpression.h"


#include "engine/sparqlExpressions/LiteralExpression.h"
#include "engine/sparqlExpressions/NaryExpression.h"
#include "engine/sparqlExpressions/SparqlExpressionGenerators.h"
#include "engine/sparqlExpressions/SparqlExpressionValueGetters.h"
#include "global/ValueIdComparators.h"

using namespace std::literals;

namespace sparqlExpression::detail {

// ____________________________________________________________________________

namespace sparqlExpression {
// ___________________________________________________________________________
DatatypeExpression::DatatpyeExpression(
    SparqlExpression::Ptr child)
    : child_{std::move(child)} {
  }
}

// ___________________________________________________________________________
ExpressionResult DatatypeExpression::evaluate(
    sparqlExpression::EvaluationContext* context) const {
  auto resultAsVariant = child_->evaluate(context);
  auto variablePtr = std::get_if<Variable>(&resultAsVariant);
  AD_CONTRACT_CHECK(variablePtr);
  if (variablePtr.hasDatatype(){
    return variablePtr.getDatatype();
  } else {
    return Datatype::UNDEF;
  }
  AD_FAIL();
}
}  // namespace sparqlExpression
