# pisoEFoam

There was a lack of electrohydrodynamics in OpenFOAM until ["rheotool"](https://github.com/fppimenta/rheoTool) was emerged. Whereas it was virtually complete, there was a room for completion. Basically this was due to two reasons;
1. It doesn't cover turbulence
2. It doesn't include PISO algorithm.

pisoEFoam is an answer to this need. It is the extended version of rheoEFoam which uses PISO as the solution algorithm and covers turbulent flows. 

### Prerequisites

To compile the solver, "You NEED to have OpenFOAM 4 installed".

### Installing

 Then follow these steps:
1. After you un-zip the folder, go to the folder : 
```
pisoEFoam/solvers/pisoEFoam
```
2. Open a terminal and type this: 
```
wmake pisoEFoam.C
```
And that's it!Your new solver is ready to use.

## Authors

* **Ali Shayegh** - *Initial work* - [Ali Shayegh](https://github.com/amuzeshi)

## License

This project is licensed under the GPL v3 License.

## Acknowledgments

* I'd like to say thanks to [Francisco Pimenta](https://github.com/fppimenta) who provided rheotool repository.
