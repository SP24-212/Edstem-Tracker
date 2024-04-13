from setuptools import setup

setup(
    name='EdStem-Tracker',
    version='0.1',
    packages=['integration'],
    install_requires=[
        'colorama'
    ],
    dependency_links=[
        'git+https://github.com/trevmoy/edapiwl.git'
    ]
)