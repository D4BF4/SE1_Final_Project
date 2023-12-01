#!/usr/bin/env python

"""The setup script."""

from setuptools import setup, find_packages

with open('README.rst') as readme_file:
    readme = readme_file.read()

with open('HISTORY.rst') as history_file:
    history = history_file.read()

requirements = ['Click>=7.0', ]

test_requirements = ['pytest>=3', ]

setup(
    author="SE1_Final_Project",
    author_email='audreyr@example.com',
    python_requires='>=3.6',
    classifiers=[
        'Development Status :: 2 - Pre-Alpha',
        'Intended Audience :: Developers',
        'License :: OSI Approved :: GNU General Public License v3 (GPLv3)',
        'Natural Language :: English',
        'Programming Language :: Python :: 3',
        'Programming Language :: Python :: 3.6',
        'Programming Language :: Python :: 3.7',
        'Programming Language :: Python :: 3.8',
    ],
    description="Final project for SE1. Simple game that is accessible to the visually impaired.",
    entry_points={
        'console_scripts': [
            'se1_project=se1_project.cli:main',
        ],
    },
    install_requires=requirements,
    license="GNU General Public License v3",
    long_description=readme + '\n\n' + history,
    include_package_data=True,
    keywords='se1_project',
    name='se1_project',
    packages=find_packages(include=['se1_project', 'se1_project.*']),
    test_suite='tests',
    tests_require=test_requirements,
    url='https://github.com/D4BF4/se1_project',
    version='0.1.0',
    zip_safe=False,
)
