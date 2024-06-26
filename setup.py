from setuptools import setup

setup(
    name='edstem-assignment-tracker',
    version='1.1.0',
    description='Edstem Assignment Tracker.',
    long_description='Edstem Assignment Tracker is a python package that allows you to easily track your assignments for the Edstem platform. It is a CLI tool that allows you to seamlessly interact with your edstem assignments and view information such as grades, due dates, and more.',
    author='Trevor Moy',
    author_email='trevormoy14@uri.edu',
    url='https://github.com/SP24-212/Edstem-Tracker',
    packages=['edstem.integration',
              'edstem.integration.storage'],
    package_data={'edstem.integration': ['*.txt'],
                  'edstem.integration.storage': ['*.h']},
    include_package_data=True,
    scripts=['edstem/integration/storage/compile.py'],  # Python scripts
    install_requires=['edapiwl==0.0.3',
                       'colorama'],  # Python dependencies
    classifiers=[
        'Programming Language :: Python :: 3',
        'License :: OSI Approved :: MIT License',
        'Operating System :: OS Independent',
    ],
    entry_points={
        'console_scripts': [
            'ed-tracker = edstem.integration.run_eat:main',
            'generate-env = edstem.integration.generate_env:main'
        ]
    }
)