# pisoEFoam

There was a lack of electrohydrodynamics in OpenFOAM until "rheotool" was emerged. Whereas it was virtually complete, there was a room for completion. Basically this was due to two reasons;
1- It doesn't cover turbulence
2- It doesn't include PISO algorithm.
pisoEFoam is an answer to this need. It is the extended version of rheoEFoam which uses PISO as the solution algorithm and covers turbulent flows. 

### Prerequisites

To compile the solver, "You NEED to have OpenFOAM 4 installed".

### Installing

 Then follow these steps:
1- After you un-zip the folder, go to the folder : pisoEFoam/solvers/pisoEFoam
2- Open a terminal and type this: wmake pisoEFoam.C
And that's it!Your new solver is ready to use.

## Authors

* **Ali Shayegh** - *Initial work* - [PurpleBooth](https://github.com/amuzeshi)

## License

This project is licensed under the GPL v3 License - see the [LICENSE.md](LICENSE.md) file for details

## Acknowledgments

* I'd like to say thanks toFrancisco Pimenta who provided rheotool repository.
