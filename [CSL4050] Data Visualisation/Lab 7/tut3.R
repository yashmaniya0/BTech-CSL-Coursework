library(shiny)
library(ggplot2)

wine_data <- read.csv("WineQT.csv")

ui <- fluidPage(
  titlePanel("Scatter Plot of Fixed Acidity vs Volatile Acidity"),
  mainPanel(
    plotOutput("scatter_plot")
  )
)

server <- function(input, output) {
  
  output$scatter_plot <- renderPlot({
    ggplot(wine_data, aes(x = fixed.acidity, y = volatile.acidity)) +
      geom_point() +
      labs(title = "Scatter Plot of Fixed Acidity vs Volatile Acidity", x = "Fixed Acidity", y = "Volatile Acidity")
  })
}

shinyApp(ui = ui, server = server)
