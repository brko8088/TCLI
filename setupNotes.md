# Concept for Set Up
As a developer I use both Mac and Windows environments (possibly Linux in the future). As you might had guess both systems require different setups. This is a guide intended to document how I might go about setting up a repo that works for both Mac and Windows users, (and possibly linux ones). 

### First option:
  - Store the project files with your repo, usually in a dedicated folder
    - msvc (with version)
    - xcode
    - makefile
    - qt creator
    - kdevelop
    - etc....

This will/can get annoying but it is usually where most people starting to learn to program go. It isn't too bad so long as you realize you'll probably have problems sharing your project as no one has 'quite' the same exact setup as you.


### Second option:
  - generalize the c++ with another build-system like CMake

This is where most projects usually end up. You need to learn the intricacies of something like CMake but once you learn, projects can be made for almost any IDE/environment.
