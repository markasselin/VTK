vtk_add_test_cxx(vtkIOLegacyCxxTests tests
  TestLegacyCompositeDataReaderWriter.cxx,NO_VALID
  TestLegacyGhostCellsImport.cxx
  TestLegacyMappedUnstructuredGrid.cxx,NO_DATA,NO_VALID
  TestLegacyArrayMetaData.cxx,NO_VALID
  )
vtk_test_cxx_executable(vtkIOLegacyCxxTests tests
    RENDERING_FACTORY
    )
