Here's how you can work through this workshop following along at
your computer.

Prerequisites:

1. Download and install CMake 2.8
2. Download and unpack boost 1.55 somewhere on your local machine.
   You do not need built libraries for this workshop.
3. Download and unpack Turtle 1.2.5 somewhere on your local machine.
   Turtle is a header-only library.

Understanding the slides:

Each slide has a folder icon in the upper right with a number on it
identifying the snapshot that corresponds to the code on the slide.
Many snapshots are associated with multiple slides as the explanation
proceeds.

Each slide has an icon in the lower-right corner that indicates if the
code is currently failing (red X), passing (green check mark) or being
refactored (green triangular cyclic arrow).  The changes being made
in each slide are shown in blue and error messages are shown in yellow.

Bootstrapping your workspace:

1. Create a directory for your workspace on your local machine.
2. Start by copying the contents of the snapshot directory 0 to your
   workspace.  Follow along with the slides and edit LocalPaths.txt at
   the appropriate time.  This is the only file you should need to edit by
   hand.  Snapshot 0 contains an initial version of this file with a
   path that is almost certainly wrong for your machine.
3. As directed in the sldies, run CMake to bootstrap your build.
4. CMake should then automatically regenerate your build every time
   CMakeLists.txt or LocalPaths.txt changes when you build the code.
   If not, you can re-run the CMake command to regenerate your build
   from the CMakeLists.txt and LocalPaths.txt files.
5. As you proceed through the workshop, copy the contents of the numbered
   snapshot to your workspace, overwriting all files.  LocalPaths.txt,
   which contains paths specific to your local machine, is only present
   in snapshot 0 and will not be overwritten from other snapshots.

Working the hangman game exercise problem:

Use a CMake build recipe similar to the one used in the slides to get your
build going ASAP -- just copy the workspace CMakeLists.txt and
LocalPaths.txt to your exercise workspace and edit appropriately. Consult
the Boost.Test documentation rewrite included with the presentation and
the Turtle documentation included in it's distribution for a reference to
assertion macros and more options for the mock object framework.
