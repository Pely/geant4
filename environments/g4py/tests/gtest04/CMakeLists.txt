configure_file(test.py test.py)
add_test(NAME geant4py-test04 COMMAND ${PYTHON_EXECUTABLE} test.py)
set_tests_properties(geant4py-test04 PROPERTIES ENVIRONMENT "PYTHONPATH=${GEANT4_PYTHON_OUTPUT_DIR};${GEANT4_TEST_ENVIRONMENT}")
