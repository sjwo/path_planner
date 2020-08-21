# Path Planer node
ROS node to interface with an ASV path planner

## Requirements
This package is meant to work in CCOMJHC's Project 11 simulation environment, the installation instructions for which are found <a href="https://github.com/CCOMJHC/project11_documentation/blob/master/SettingUpASimulationEnvironment.md">here</a>. It also uses a MPC ROS node, found <a href="https://github.com/afb2001/mpc">here</a>.

This package was developed solely on Ubuntu 18.04, so try anything else at your own risk.

## Installation
Install the <a href="https://github.com/CCOMJHC/project11_documentation/blob/master/SettingUpASimulationEnvironment.md">CCOMJHC Project 11 simulation environment</a>. MOOS-IvP components  are not required.

Installing the simulation environment will clone this repository and the associated <a href="https://github.com/afb2001/mpc">model predictive controller</a>. No additional setup is required.

There is a test scenario runner node that's in development, which is <a href="https://github.com/afb2001/test_scenario_runner.git">here</a>. It includes a suite of scenarios. See the README of that repository for instructions on how to use the test runner.

## Usage
See the simulation environment documentation for instructions on getting that running. The planner and controller nodes are included in the standard launch files. Once everything is running, use the dynamic_reconfigure window to switch the path follower to the path planner, in the mission_manager parameter section.

Software documentation can be generated by running <code>generate_docs.sh</code>, which runs <code>doxygen</code> on this package and the controller package, generating linked HTML docs.

###Visualizer
This package has a visualizer, found in <code>path_planner/src/visualizer.py</code>. It expects as input a visualization file created by the planner and an optional map file to display. 
Vertices generated (and not pruned) during search are drawn in a cost-dependent color, with trajectories sharing the ending vertex color. Samples are shown as grey dots. Ribbons are shown as red lines. Blocked squares in the map are shown in black. The final (goal) trajectory, if found in an iteration, is overlayed with blue dots at the end. If an incumbent solution is present for a search iteration, its cost is shown in the upper left.

The visualizer allows a user to walk through each iteration of search with specific keyboard inputs, as follows:

<code>arrow keys</code>: Pan the map.\
<code>-</code>: Zoom out. \
<code>=</code>: Zoom in. \
<code>esc</code>: Exit. \  
<code>n</code>: Display the next sample. When a search iteration is complete it wraps around and restarts. \
<code>b</code> or <code>backspace</code>: Stop displaying the most recent sample, effectively walking backward in time. Similarly wraps around to the end of search when at the beginning. \
<code>k</code>: Jump to the next search iteration. Hold <code>shift</code> to jump to the next search iteration where a goal is found. \
<code>j</code>: Jump to the previous search iteration. Hold <code>shift</code> to jump to the last previous iteration where a goal is found. \
<code>t</code>: Toggle showing trajectories. \
<code>s</code>: Toggle showing samples. \
<code>r</code>: Toggle showing ribbons. \
<code>v</code>: Toggle showing vertices. \
<code>c</code>: Toggle showing vertex costs. \
<code>f</code>: Toggle showing costs as floats vs ints.  