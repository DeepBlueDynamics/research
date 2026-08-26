# Configuration file for the Sphinx documentation builder.
#
# This file only contains a selection of the most common options. For a full
# list see the documentation:
# https://www.sphinx-doc.org/en/master/usage/configuration.html

# -- Path setup --------------------------------------------------------------

# If extensions (or modules to document with autodoc) are in another directory,
# add these directories to sys.path here. If the directory is relative to the
# documentation root, use os.path.abspath to make it absolute, like shown here.
#
import os
import sys

sys.path.insert(0, os.path.abspath('.'))

# -- Project information -----------------------------------------------------

from version import __version__

project = 'pntOS'
copyright = '2019-2026'
author = 'IS4S'

# The full version, including alpha/beta/rc tags
release = __version__
version = __version__


# -- General configuration ---------------------------------------------------

# Add any Sphinx extension module names here, as strings. They can be
# extensions coming with Sphinx (named 'sphinx.ext.*') or your custom
# ones.
extensions = [
    'breathe',
    'exhale',
    'sphinx.ext.autosectionlabel',
    'sphinx.ext.mathjax',
]

breathe_projects = {"pntOS API project": "./doxygen_output/xml"}
breathe_default_project = "pntOS API project"

# Setup the exhale extension
exhale_args = {
    # These arguments are required
    "containmentFolder": "./pntos-api-exhale",
    "rootFileName": "library_root.rst",
    "rootFileTitle": "pntOS Architecture API",
    "doxygenStripFromPath": "..",
    # Suggested optional arguments
    "createTreeView": True,
    # TIP: if using the sphinx-bootstrap-theme, you need
    # "treeViewIsBootstrap": True,
    "exhaleExecutesDoxygen": True,
    # EXTRACT_ALL
    #    If the EXTRACT_ALL tag is set to YES, doxygen will assume all entities
    #    in documentation are documented, even if no documentation was
    #    available. Private class members and static file members will be
    #    hidden unless the EXTRACT_PRIVATE respectively EXTRACT_STATIC tags are
    #    set to YES.
    # FILE_PATTERNS
    #    If the value of the INPUT tag contains directories, you can use the
    #    FILE_PATTERNS tag to specify one or more wildcard patterns (like *.cpp
    #    and *.h) to filter out the source-files in the directories.
    # INPUT
    #    The INPUT tag is used to specify the files and/or directories that
    #    contain documented source files.
    # PREDEFINED
    #    The PREDEFINED tag can be used to specify one or more macro names that
    #    are defined before the preprocessor is started (similar to the -D
    #    option of e.g. gcc).
    #    In particular, we use this option to comment out instances of
    #    PNTOS_NULLABLE and PNTOS_ASSUME_NONNULL_BEGIN, since they mess up the
    #    docs tools from parsing the API correctly.
    # OPTIMIZE_OUTPUT_FOR_C
    #     Set the OPTIMIZE_OUTPUT_FOR_C tag to YES if your project consists of
    #     C sources only. Doxygen will then generate output that is more
    #     tailored for C. For instance, some of the names that are used will be
    #     different. The list of all members will be omitted, etc.
    "exhaleDoxygenStdin": """
        EXTRACT_ALL = YES
        FILE_PATTERNS = *.h *.hpp
        INPUT = ../api/include
        PREDEFINED += PNTOS_NULLABLE=/*PNTOS_NULLABLE*/
        PREDEFINED += PNTOS_ASSUME_NONNULL_BEGIN=/*PNTOS_ASSUME_NONNULL_BEGIN*/
        OPTIMIZE_OUTPUT_FOR_C = YES
    """,
}

# Tell sphinx what the primary language being documented is.
primary_domain = 'cpp'

# Tell sphinx what the pygments highlight language should be.
highlight_language = 'cpp'

# Add any paths that contain templates here, relative to this directory.
templates_path = ['_templates']

# List of patterns, relative to source directory, that match files and
# directories to ignore when looking for source files.
# This pattern also affects html_static_path and html_extra_path.
exclude_patterns = ['_build', 'Thumbs.db', '.DS_Store']


# -- Options for HTML output -------------------------------------------------

# The theme to use for HTML and HTML Help pages.  See the documentation for
# a list of builtin themes.
#
html_theme = 'sphinx_rtd_theme'

# Add any paths that contain custom static files (such as style sheets) here,
# relative to this directory. They are copied after the builtin static files,
# so a file named "default.css" will overwrite the builtin "default.css".
branding_dir = '../subprojects/pntos-data/docs/branding/'
html_static_path = ['_static', branding_dir, '../subprojects/MathJax/']

# Relative to _static directory
mathjax_path = 'es5/tex-mml-chtml.js'

html_logo = branding_dir + "pntOs_Logo_Gradient_Light_Horizontal.png"
html_theme_options = {'logo_only': True}

suppress_warnings = ['autosectionlabel.*']


def setup(app):
    app.add_css_file('pntos.css')
    app.add_css_file('hk-grotesk.css')
