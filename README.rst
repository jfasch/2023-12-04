Development Workflow
====================

.. contents::
   :local:

Checkout and Initialization
---------------------------

.. code-block:: console

   $ cd ~/My-Projects                       # <--- or wherever you like
   $ git clone https://github.com/jfasch/2023-12-04.git
   $ cd 2023-12-04/
   $ git submodule init
   $ git submodule update

Build
-----

Create build directory for Intel architecture (``x86_64``)

.. code-block:: console

   $ mkdir ~/My-Builds/2023-12-04-x86_64         # <--- or wherever you like
   $ cd ~/My-Builds/2023-12-04-x86_64
   $ cmake ~/My-Projects/2023-12-04
   $ make

Test
----

.. code-block:: console

   $ pwd
   /home/jfasch/My-Builds/2023-12-04      # <--- or whatever you have chosen

.. code-block:: console

   $ ./tests/test-suite 
   Running main() from /home/jfasch/My-Projects/2023-12-04/googletest/googletest/src/gtest_main.cc
   [==========] Running 4 tests from 2 test suites.
   [----------] Global test environment set-up.
   [----------] 2 tests from sensor_mock_suite
   [ RUN      ] sensor_mock_suite.basic
   [       OK ] sensor_mock_suite.basic (0 ms)
   [ RUN      ] sensor_mock_suite.is_a_sensor
   [       OK ] sensor_mock_suite.is_a_sensor (0 ms)
   [----------] 2 tests from sensor_mock_suite (0 ms total)
   
   [----------] 2 tests from w1_sensor_suite
   [ RUN      ] w1_sensor_suite.read_sensor
   [       OK ] w1_sensor_suite.read_sensor (0 ms)
   [ RUN      ] w1_sensor_suite.no_decimal_places_lost
   [       OK ] w1_sensor_suite.no_decimal_places_lost (0 ms)
   [----------] 2 tests from w1_sensor_suite (0 ms total)
   
   [----------] Global test environment tear-down
   [==========] 4 tests from 2 test suites ran. (0 ms total)
   [  PASSED  ] 4 tests.
    
