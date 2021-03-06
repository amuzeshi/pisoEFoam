/*---------------------------------------------------------------------------*\
  =========                 |
  \\      /  F ield         | OpenFOAM: The Open Source CFD Toolbox
   \\    /   O peration     |
    \\  /    A nd           | Copyright held by original author
     \\/     M anipulation  |
-------------------------------------------------------------------------------
License
    This file is part of OpenFOAM.

    OpenFOAM is free software; you can redistribute it and/or modify it
    under the terms of the GNU General Public License as published by the
    Free Software Foundation; either version 2 of the License, or (at your
    option) any later version.

    OpenFOAM is distributed in the hope that it will be useful, but WITHOUT
    ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
    FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
    for more details.

    You should have received a copy of the GNU General Public License
    along with OpenFOAM; if not, write to the Free Software Foundation,
    Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA

 

\*---------------------------------------------------------------------------*/

#ifndef Ohmic_H
#define Ohmic_H

#include "EDFEquation.H"

namespace Foam
{

class Ohmic
:
    public EDFEquation
{
    // Private data

        //- Externally applied electric potential
        volScalarField sigma_;

        //- Internal electric potential
        volScalarField phiE_;

        //- Model constants

            // Electrical permittivity of the fluid
            dimensionedScalar relPerm_;
            
            // Effective diffusivity (m2/s)     
            dimensionedScalar Deff_;
          
       //- Extra electric field (optional)
       dimensionedVector extraE_;

       //- Solution controls for phiE and sigma
          
            // Residuals treshold
            scalar sigmaEqRes_;
            scalar phiEEqRes_;
            
            // Max number of iterations
            int maxIterSigma_;
            int maxIterPhiE_;
            
       class OhSpecie
          {   
              
            //- Model parameters
            
              // Ionic valence (-)     
                dimensionedScalar zi_;
                
              // Diffusion coefficient (m2/s)     
                dimensionedScalar Di_;
                
              // Species name     
                word namei_;  
          
           // Private Member Functions

              //- Disallow default bitwise copy construct
                OhSpecie(const OhSpecie&);

              //- Disallow default bitwise assignment
                void operator=(const OhSpecie&);
                
              public:
              
               // Constructor
               
                OhSpecie
                (
                    const word& name,
                    const surfaceScalarField& phi,
                    const dictionary& dict
                );
              
               // Destructor
               ~OhSpecie() {}
             
             // Public Member Functions 
             
             // Const-access to zi   
              const dimensionedScalar zi() const
               {
                   return zi_;
               } 
               
             // Const-access to Di   
              const dimensionedScalar Di() const
               {
                   return Di_;
               }
               
             // Const access to namei   
              const word namei() const
               {
                   return namei_;
               }  
       };
       
       //- List of species
       PtrList<OhSpecie> species_;
       
       //- Number of species
       int nSpecies_;

    // Private Member Functions

        //- Disallow default bitwise copy construct
        Ohmic(const Ohmic&);

        //- Disallow default bitwise assignment
        void operator=(const Ohmic&);
     
public:

    //- Runtime type information
    TypeName("Ohmic");

    // Constructors

        //- Construct from components
        Ohmic
        (
            const word& name,
            const surfaceScalarField& phi,
            const dictionary& dict
        );


    // Destructor

        virtual ~Ohmic()
        {}


    // Member Functions

        //- Return the electric force for the momentum equation
         virtual tmp<volVectorField> Fe() const;

        //- Update the electric force
        virtual void correct();
};


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace Foam

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif

// ************************************************************************* //
