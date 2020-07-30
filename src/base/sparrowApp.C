#include "sparrowApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

InputParameters
sparrowApp::validParams()
{
  InputParameters params = MooseApp::validParams();

  // Do not use legacy DirichletBC, that is, set DirichletBC default for preset = true
  params.set<bool>("use_legacy_dirichlet_bc") = false;

  return params;
}

sparrowApp::sparrowApp(InputParameters parameters) : MooseApp(parameters)
{
  sparrowApp::registerAll(_factory, _action_factory, _syntax);
}

sparrowApp::~sparrowApp() {}

void
sparrowApp::registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  ModulesApp::registerAll(f, af, s);
  Registry::registerObjectsTo(f, {"sparrowApp"});
  Registry::registerActionsTo(af, {"sparrowApp"});

  /* register custom execute flags, action syntax, etc. here */
}

void
sparrowApp::registerApps()
{
  registerApp(sparrowApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
extern "C" void
sparrowApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  sparrowApp::registerAll(f, af, s);
}
extern "C" void
sparrowApp__registerApps()
{
  sparrowApp::registerApps();
}
