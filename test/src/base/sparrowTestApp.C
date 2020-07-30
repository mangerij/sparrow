//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html
#include "sparrowTestApp.h"
#include "sparrowApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "MooseSyntax.h"
#include "ModulesApp.h"

InputParameters
sparrowTestApp::validParams()
{
  InputParameters params = sparrowApp::validParams();
  return params;
}

sparrowTestApp::sparrowTestApp(InputParameters parameters) : MooseApp(parameters)
{
  sparrowTestApp::registerAll(
      _factory, _action_factory, _syntax, getParam<bool>("allow_test_objects"));
}

sparrowTestApp::~sparrowTestApp() {}

void
sparrowTestApp::registerAll(Factory & f, ActionFactory & af, Syntax & s, bool use_test_objs)
{
  sparrowApp::registerAll(f, af, s);
  if (use_test_objs)
  {
    Registry::registerObjectsTo(f, {"sparrowTestApp"});
    Registry::registerActionsTo(af, {"sparrowTestApp"});
  }
}

void
sparrowTestApp::registerApps()
{
  registerApp(sparrowApp);
  registerApp(sparrowTestApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
// External entry point for dynamic application loading
extern "C" void
sparrowTestApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  sparrowTestApp::registerAll(f, af, s);
}
extern "C" void
sparrowTestApp__registerApps()
{
  sparrowTestApp::registerApps();
}
